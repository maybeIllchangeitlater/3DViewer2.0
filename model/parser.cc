#include "parser.h"

#include <fstream>
#include <iostream>
namespace s21 {

void s21::ObjParser::ParseFile() {
  Clear();

  QFile file(filename_);
  if (!file.exists() || !file.open(QIODevice::ReadOnly)) {
    file.close();
    emit ParseOver(false);
    return;
  }

  AddZeros();

  while (!file.atEnd()) {
    QByteArray data(file.readLine());
    if (data[0] == 'v' && data[1] == ' ') {
      if (PushPoint(data, tmp_vertex_) != 3) {
        file.close();
        emit ParseOver(false);
        return;
      }
    } else if (data[0] == 'v' && data[1] == 'n'){
        if(PushPoint(data, tmp_normal_) != 3){
            file.close();
            emit ParseOver(false);
            return;
        }
    } else if(data[0] == 'v' && data[1] == 't'){
        if(PushPoint(data, tmp_texture_) != 2){
            file.close();
            emit ParseOver(false);
            return;
        }
    }else if (data[0] == 'f' && data[1] == ' ') {
      if (!ParseFace(data)) {
        file.close();
        emit ParseOver(false);
        return;
      }
    }
  }

  file.close();

  for (int i = 0; i < data_.size() / OBJECT_PROPERTIES_COUNT; ++i) {
      indices_.emplaceBack(i);
  }

  ChangeFilename();
  emit ParseOver(true);
}

template<typename Coordinatable>
size_t ObjParser::PushPoint(QByteArray &data, Coordinatable &target) {
  target.emplaceBack();
  auto cstr = data.data();
  size_t size = 0, sizeline_counter = 0;
  while (*cstr != EOF && *cstr != '\n') {
      while (!(IsNumber(*cstr))){
          ++cstr;
      }
      while (IsNumber(*(cstr + size))){
          ++size;
      }

      try{
          target.back()[sizeline_counter] = std::stof(cstr);
      }catch(...){
          return SIZE_MAX;
      }

    cstr += size;
    size = 0;
    ++sizeline_counter;
  }
  return sizeline_counter;
}

bool ObjParser::ParseFace(QByteArray &data) {
    auto cstr = data.data();
    size_t data_size = data.size();
    size_t index = 0;
    QVector<float> polygon_raw;

    while(*cstr != EOF && *cstr != '\n'){

        SkipUntilNextDigit(index, data_size, cstr);
        if(index >= data_size || !ToVerticeData(cstr, polygon_raw, tmp_vertex_)){
            return false;
        }

        SkipUntilNextFace(index, data_size, cstr);
        if(index >= data_size || !ToVerticeData(cstr, polygon_raw, tmp_texture_)){
            return false;
        }

        SkipUntilNextFace(index, data_size, cstr);
        if(index >= data_size || !ToVerticeData(cstr, polygon_raw, tmp_normal_)){
            return false;
        }
    }

    CutEars(polygon_raw);

    return true;
}

void ObjParser::AddZeros()
{
    tmp_vertex_.push_back({0,0,0});
    tmp_texture_.push_back({0,0});
    tmp_normal_.push_back({0,0,0});
}

void ObjParser::Clear()
{
    data_.clear();
    indices_.clear();
    tmp_vertex_.clear();
    tmp_texture_.clear();
    tmp_normal_.clear();
}

void ObjParser::CutEars(QVector<float> &polygon_raw)
{
    QVector<float> triangled;
    while(polygon_raw.size() > 3 * OBJECT_PROPERTIES_COUNT){
        bool ear_clipped = false;
        for(auto iter = polygon_raw.begin(); iter != polygon_raw.end(); iter+=OBJECT_PROPERTIES_COUNT){
            if(IsEar(polygon_raw, iter)){
                ear_clipped = true;
                auto ear_iter = iter;
                if(iter == polygon_raw.begin()){
                    auto previous = polygon_raw.end() - OBJECT_PROPERTIES_COUNT;
                    for(size_t i = 0; i < OBJECT_PROPERTIES_COUNT; ++i){
                        triangled.emplaceBack(*previous++);
                    }
                    for(size_t i = 0; i < OBJECT_PROPERTIES_COUNT * 2; ++i){
                        triangled.emplaceBack(*iter++);
                    }
                }else{
                    for(size_t i = 0; i < OBJECT_PROPERTIES_COUNT * 3; ++i){
                        triangled.emplaceBack(*iter++);
                    }
                }
                polygon_raw.erase(ear_iter, ear_iter + OBJECT_PROPERTIES_COUNT);
                break;
            }
        }
        if(!ear_clipped){
            ClipMinimalAngle(polygon_raw);
        }
    }
    if(polygon_raw.size() == 3 * OBJECT_PROPERTIES_COUNT){
        triangled += polygon_raw;
    }
    data_ += triangled;
}

bool ObjParser::IsEar(QVector<float> &polygon_raw, QList<float>::Iterator &point)
{
    auto [previous, current, next] = GetPreviousCurrentNext(polygon_raw, point);
    // Check if the angle at the current vertex is concave (counterclockwise order)
    double cross_product
            = CrossProduct(std::make_pair(previous.x, previous.y),
                           std::make_pair(current.x, current.y),
                           std::make_pair(next.x, next.y));
    bool counterclockwise = true;
    if(cross_product >= 0){
        std::swap(previous, next);
        counterclockwise = false;
    }

    auto previous_iter = point == polygon_raw.begin()
            ? polygon_raw.end() - OBJECT_PROPERTIES_COUNT
            : point - OBJECT_PROPERTIES_COUNT;
    auto next_iter = point == polygon_raw.end() - 1
            ? polygon_raw.begin()
            : point + OBJECT_PROPERTIES_COUNT;

    // Check that there are no other vertices inside the triangle
    for (auto iter = polygon_raw.begin(); iter != polygon_raw.end(); iter+=OBJECT_PROPERTIES_COUNT) {
        if (iter != point && iter != previous_iter && iter != next_iter) {

            Vertex p{*iter, *(iter + 1), *(iter + 2)};
                // Check if the point is inside the triangle
            double cross_product1 =
                    CrossProduct(std::make_pair(previous.x, previous.y),
                                 std::make_pair(current.x, current.y),
                                 std::make_pair(p.x, p.y));
            double cross_product2 =
                    CrossProduct(std::make_pair(previous.x, previous.y),
                                 std::make_pair(p.x, p.y),
                                 std::make_pair(next.x, next.y));
            double cross_product3 =
                    CrossProduct(std::make_pair(p.x, p.y),
                                 std::make_pair(current.x, current.y),
                                 std::make_pair(next.x, next.y));
            double cross_product4 =
                    CrossProduct(std::make_pair(previous.x, previous.z),
                                 std::make_pair(current.x, current.z),
                                 std::make_pair(p.x, p.z));
            double cross_product5 =
                    CrossProduct(std::make_pair(previous.x, previous.z),
                                 std::make_pair(p.x, p.z),
                                 std::make_pair(next.x, next.z));
            double cross_product6 =
                    CrossProduct(std::make_pair(p.x, p.z),
                                 std::make_pair(current.x, current.z),
                                 std::make_pair(next.x, next.z));
            if(counterclockwise){
                if (cross_product1 >= 0 && cross_product2 >= 0 && cross_product3 >= 0
                        && cross_product4 >= 0 && cross_product5 >= 0 && cross_product6 >= 0) {
                    return false;
                }
            }else{
                if (cross_product1 <= 0 && cross_product2 <= 0 && cross_product3 <= 0
                        && cross_product4 <= 0 && cross_product5 <= 0 && cross_product6 <= 0) {
                    return false;
                }
            }
        }
    }
    return true;
}

void ObjParser::ClipMinimalAngle(QVector<float> &polygon_raw)
{
    double minimal_angle = std::numeric_limits<double>::max();
    double current_angle;
    auto minimal_angle_iter = polygon_raw.begin();
    for(auto iter = polygon_raw.begin(); iter != polygon_raw.end();
        iter+=OBJECT_PROPERTIES_COUNT){
        current_angle = CalculateAngle(polygon_raw, iter);
        if(minimal_angle > current_angle){
            minimal_angle = current_angle;
            minimal_angle_iter = iter;
        }
    }
    polygon_raw.erase(minimal_angle_iter,
                      minimal_angle_iter + OBJECT_PROPERTIES_COUNT);
}

double ObjParser::CalculateAngle(QVector<float> &polygon_raw, QVector<float>::Iterator &point)
{
    auto [previous, current, next] = GetPreviousCurrentNext(polygon_raw, point);

    //vectors p-c and c-n
    double pc_x = current.x - previous.x;
    double pc_y = current.y - previous.y;
    double cn_x = next.x - current.x;
    double cn_y = next.y - current.y;

    double dot = pc_x * cn_x + pc_y * cn_y;
    double cross = pc_x * cn_y - pc_y * cn_x;

    //in radians
    return std::atan2(cross, dot);
}

double ObjParser::CrossProduct(const std::pair<float, float> p1,
            const std::pair<float, float> p2,
            const std::pair<float, float> p3) const noexcept
{
    return (p2.first - p1.first) * (p3.second - p2.second)
            - (p3.first - p2.first) * (p2.second - p1.second);
}

std::tuple<Vertex, Vertex, Vertex> ObjParser::GetPreviousCurrentNext(QVector<float> &polygon_raw,
                                                                     QVector<float>::Iterator &point)
{
    Vertex current{*point, *(point + 1), *(point + 2)};
    Vertex previous;
    Vertex next;
    if(point != polygon_raw.begin()){
        previous = {*(point - OBJECT_PROPERTIES_COUNT),
                        *(point - OBJECT_PROPERTIES_COUNT + 1),
                    *(point - OBJECT_PROPERTIES_COUNT + 2)};
    }else{
        previous = {*(polygon_raw.end() - OBJECT_PROPERTIES_COUNT),
                    *(polygon_raw.end() - OBJECT_PROPERTIES_COUNT + 1),
                    *(polygon_raw.end() - OBJECT_PROPERTIES_COUNT + 2)};
    }
    if(point != polygon_raw.end() - OBJECT_PROPERTIES_COUNT){
            next = {*(point + OBJECT_PROPERTIES_COUNT),
                            *(point + OBJECT_PROPERTIES_COUNT + 1),
                    *(point + OBJECT_PROPERTIES_COUNT + 2)};
        }else{
            next = {*(polygon_raw.begin()),
                        *(polygon_raw.begin() + 1),
                    *(polygon_raw.begin() + 2)};
        }

    return std::make_tuple(std::move(previous), std::move(current), std::move(next));
}


void ObjParser::SkipUntilNextDigit(size_t &index, size_t data_size, char *&data)
{
    while (index < data_size && !std::isspace(*data)) {
      ++data;
      ++index;
    }
    while (index < data_size && !(std::isdigit(*data))) {
      ++data;
      ++index;
    }
}

void ObjParser::SkipUntilNextFace(size_t &index, size_t data_size, char *&data)
{
    while (index < data_size && *data != '/'){
        ++data;
        ++index;
    }
    ++data;
    ++index;
}

bool ObjParser::IsNumber(char c)
{
    return std::isdigit(c) || c == '.' || c == '-' || c == '+';
}

void ObjParser::ChangeFilename() noexcept {
  filename_ = filename_.mid(filename_.lastIndexOf("/") + 1).chopped(4) + "\n" +
              "Vertexes: " + QString::number(tmp_vertex_.size() / 3) +
          " Edges: " + QString::number(indices_.size() / 2);
}

template<typename Coordinatable>
bool ObjParser::ToVerticeData(char *&data, QList<float> &polygon_raw, Coordinatable &from)
{
    short size = 0;
    while(IsNumber(*(data + size))){
        ++size;
    }
    int ind = std::stoi(data);
    data += size;
    size = 0;
    if(ind >= from.size()){
        return false;
    }
    if(ind < 0) {
        ind += from.size();
    };
    polygon_raw.emplaceBack(from[ind].x);
    polygon_raw.emplaceBack(from[ind].y);

    if constexpr(std::is_same_v<Coordinatable, QVector<Vertex>>){
        polygon_raw.emplaceBack(from[ind].z);
    }
    return true;
}

}  // namespace s21
