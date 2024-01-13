#include "earcutting.h"

namespace s21 {


std::vector<float> EarCutting::CutEars()
{
    std::vector<float> triangled;
    while(polygon_raw_.size() > 3 * OBJECT_PROPERTIES_COUNT){
        bool ear_clipped = false;
        for(auto iter = polygon_raw_.begin(); iter != polygon_raw_.end(); iter+=OBJECT_PROPERTIES_COUNT){
            if(IsEar(iter)){
                ear_clipped = true;
                auto ear_iter = iter;
                if(iter == polygon_raw_.begin()){
                    auto previous = polygon_raw_.end() - OBJECT_PROPERTIES_COUNT;
                    for(size_t i = 0; i < OBJECT_PROPERTIES_COUNT; ++i){
                        triangled.emplace_back(*previous++);
                    }
                    for(size_t i = 0; i < OBJECT_PROPERTIES_COUNT * 2; ++i){
                        triangled.emplace_back(*iter++);
                    }
                }else{
                    if(iter == polygon_raw_.end() - OBJECT_PROPERTIES_COUNT){
                        for(size_t i = 0; i < OBJECT_PROPERTIES_COUNT * 3; ++i){
                            triangled.emplace_back(*iter++);
                        }
                    }
                }
                polygon_raw_.erase(ear_iter, ear_iter + OBJECT_PROPERTIES_COUNT);
                break;
            }
        }
        if(!ear_clipped){
            ClipMinimalAngle();
        }
    }
    if(polygon_raw_.size() == 3 * OBJECT_PROPERTIES_COUNT){
        triangled.insert(triangled.end(), polygon_raw_.begin(), polygon_raw_.end());
    }
    return triangled;
}

bool EarCutting::IsEar(std::vector<float>::iterator &point)
{
    auto [previous, current, next] = GetPreviousCurrentNext(point);

    bool counterclockwise =
            VerticesPositionedCounterClockWise(previous, current, next);

    auto previous_iter = point == polygon_raw_.begin()
            ? polygon_raw_.end() - OBJECT_PROPERTIES_COUNT
            : point - OBJECT_PROPERTIES_COUNT;
    auto next_iter = point == polygon_raw_.end() - 1
            ? polygon_raw_.begin()
            : point + OBJECT_PROPERTIES_COUNT;

    // Check that there are no other vertices inside the triangle
    for (auto iter = polygon_raw_.begin(); iter != polygon_raw_.end(); iter+=OBJECT_PROPERTIES_COUNT) {
        if (iter != point && iter != previous_iter && iter != next_iter) {
            Vertex p{*iter, *(iter + 1), *(iter + 2)};
            if(PointIsInsideTriangle(p, previous, current, next, counterclockwise)){
                return false;
            }
        }
    }
    return true;
}

std::tuple<Vertex, Vertex, Vertex> EarCutting::
    GetPreviousCurrentNext(std::vector<float>::iterator &point) const
{
    Vertex current{*point, *(point + 1), *(point + 2)};
    Vertex previous;
    Vertex next;
    if(point != polygon_raw_.begin()){
        previous = {*(point - OBJECT_PROPERTIES_COUNT),
                        *(point - OBJECT_PROPERTIES_COUNT + 1),
                    *(point - OBJECT_PROPERTIES_COUNT + 2)};
    }else{
        previous = {*(polygon_raw_.end() - OBJECT_PROPERTIES_COUNT),
                    *(polygon_raw_.end() - OBJECT_PROPERTIES_COUNT + 1),
                    *(polygon_raw_.end() - OBJECT_PROPERTIES_COUNT + 2)};
    }
    if(point != polygon_raw_.end() - OBJECT_PROPERTIES_COUNT){
            next = {*(point + OBJECT_PROPERTIES_COUNT),
                            *(point + OBJECT_PROPERTIES_COUNT + 1),
                    *(point + OBJECT_PROPERTIES_COUNT + 2)};
        }else{
            next = {*(polygon_raw_.begin()),
                        *(polygon_raw_.begin() + 1),
                    *(polygon_raw_.begin() + 2)};
        }

    return std::make_tuple(std::move(previous), std::move(current), std::move(next));
}

bool EarCutting::VerticesPositionedCounterClockWise(
        Vertex &previous, Vertex &current, Vertex &next) const{
    double cross_product
            = CrossProduct(std::make_pair(previous.x, previous.y),
                           std::make_pair(current.x, current.y),
                           std::make_pair(next.x, next.y));
    if(cross_product >= 0){
        std::swap(previous, next);
        return false;
    }
    return true;
}

bool EarCutting::PointIsInsideTriangle(const Vertex &p, const Vertex &previous,
                                       const Vertex &current, const Vertex &next, bool counterclockwise) const{
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
    if (counterclockwise && cross_product1 >= 0 && cross_product2 >= 0 && cross_product3 >= 0
        && cross_product4 >= 0 && cross_product5 >= 0 && cross_product6 >= 0) {
        return true;
    }else if (!counterclockwise && cross_product1 <= 0 && cross_product2 <= 0 && cross_product3 <= 0
            && cross_product4 <= 0 && cross_product5 <= 0 && cross_product6 <= 0) {
        return true;
    }
    return false;
}

void EarCutting::ClipMinimalAngle()
{
    double minimal_angle = std::numeric_limits<double>::max();
    double current_angle;
    auto minimal_angle_iter = polygon_raw_.begin();
    for(auto iter = polygon_raw_.begin(); iter != polygon_raw_.end();
        iter+=OBJECT_PROPERTIES_COUNT){
        current_angle = CalculateAngle(iter);
        if(minimal_angle > current_angle){
            minimal_angle = current_angle;
            minimal_angle_iter = iter;
        }
    }
    polygon_raw_.erase(minimal_angle_iter,
                      minimal_angle_iter + OBJECT_PROPERTIES_COUNT);
}

double EarCutting::CalculateAngle(std::vector<float>::iterator &point) const
{
    auto [previous, current, next] = GetPreviousCurrentNext(point);

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


} // namespace s21
