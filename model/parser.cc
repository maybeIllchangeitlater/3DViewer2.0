#include "parser.h"

#include <fstream>
#include <iostream>
namespace s21 {
void s21::ObjParser::ParseFile() {
  tmp_vertex_.clear();
  tmp_face_.clear();
  QFile file(filename_);
  if (!file.exists() || !file.open(QIODevice::ReadOnly)) {
    file.close();
    emit ParseOver(false);
    return;
  }
  while (!file.atEnd()) {
    auto data(file.readLine());
    if (data[0] == 'v' && data[1] == ' ') {
      if (!PushVertex(data)) {
        file.close();
        emit ParseOver(false);
        return;
      }
    } else if (data[0] == 'f' && data[1] == ' ') {
      if (!PushFace(data)) {
        file.close();
        emit ParseOver(false);
        return;
      }
    }
  }
  file.close();
  ChangeFilename();
  *(std::max_element(tmp_face_.begin(), tmp_face_.end())) >
          (tmp_vertex_.size() / 3 - 1)
      ? emit ParseOver(false)
      : emit ParseOver(true);
}
bool ObjParser::PushVertex(QByteArray &data) {
  auto cstr = data.data();
  int size = 0, sizeline_counter = 0;
  while (*cstr != EOF && *cstr != '\n') {
    while (
        !(std::isdigit(*cstr) || *cstr == '.' || *cstr == '-' || *cstr == '+'))
      ++cstr;
    while (std::isdigit(*(cstr + size)) || *(cstr + size) == '.' ||
           *(cstr + size) == '-' || *(cstr + size) == '+')
      ++size;
    tmp_vertex_.push_back(std::stof(cstr));
    cstr += size;
    size = 0;
    ++sizeline_counter;
  }
  return sizeline_counter == 3;
}

bool ObjParser::PushFace(QByteArray &data) {
  int i = 0;
  auto cstr = data.data();
  int n = data.size();
  while (i < n && !(std::isdigit(*cstr))) {
    ++cstr;
    i++;
  }
  if (*cstr == '\n') return false;
  unsigned int first = std::stoi(cstr) - 1;
  tmp_face_.push_back(first);
  while (i < n && !std::isspace(*cstr)) {
    ++cstr;
    i++;
  }
  while (i < n && !(std::isdigit(*cstr))) {
    ++cstr;
    i++;
  }
  while (i < n) {
    tmp_face_.push_back(std::stoi(cstr) - 1);
    tmp_face_.push_back(std::stoi(cstr) - 1);
    while (i < n && !std::isspace(*cstr)) {
      ++cstr;
      i++;
    }
    while (i < n && !(std::isdigit(*cstr))) {
      ++cstr;
      i++;
    }
  }
  tmp_face_.push_back(first);
  return true;
}

void ObjParser::ChangeFilename() noexcept {
  filename_ = filename_.mid(filename_.lastIndexOf("/") + 1).chopped(4) + "\n" +
              "Vertexes: " + QString::number(tmp_vertex_.size() / 3) +
              " Edges: " + QString::number(tmp_face_.size() / 2);
}
}  // namespace s21
