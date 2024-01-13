#ifndef CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_
#define CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_

#include <QDir>
#include <cctype>
#include <limits>
#include "../utility/datastructure.h"

namespace s21 {

class ObjParser : public QObject {
  Q_OBJECT

 public:
  void ParseFile();
  /**
   * @return vertex data in format : vertex_x, vertex_y, vertex_z,
   * texture_x, texture_y, normal_x, normal_y, normal_z, repeat per each facet
   */
  QVector<float> &GetVertexDataRef() noexcept { return data_; }
  QVector<unsigned int> &GetIndicesRef() noexcept { return indices_; }
  const QString &GetFilename() const noexcept { return filename_; }

  void SetFilename(QString filename) noexcept { filename_ = filename; }

 signals:
  void ParseOver(bool);

 private:
  /**
   * @brief Add point (vertex, texture or normal) from file to corresponding container
   */
  template<typename Coordinatable>
  size_t PushPoint(QByteArray& data, Coordinatable &target);
  /**
   * @brief Add vertexes, textures and normales to vertex data vector during facet parsing
   */
  bool ParseFace(QByteArray& data);
  /**
   * @brief Adds initial 0 values to each container
   */
  void AddZeros();

  template<typename Coordinatable>
  /**
   * @brief Add point (vertex, texture or normal) from corresponding container to vertices data
   */
  bool ToVerticeData(char *&data, QList<float> &polygon_raw, Coordinatable &from);

  void Clear();
  /**
   * @brief triangulate polygon
   */
  void CutEars(QVector<float> &polygon_raw);
  bool IsEar(QVector<float> &polygon_raw, QList<float>::Iterator &point);
  void ClipMinimalAngle(QVector<float> &polygon_raw);
  double CalculateAngle(QVector<float> &polygon_raw, QVector<float>::Iterator &point);
  double CrossProduct(Vertex &p1, Vertex &p2, Vertex &p3);
  std::tuple<Vertex, Vertex, Vertex> GetPreviousCurrentNext(QVector<float> &polygon_raw, QVector<float>::Iterator &point);


  void SkipUntilNextDigit(size_t &index, size_t data_size, char *&data);
  void SkipUntilNextFace(size_t &index, size_t data_size, char *&data);
  bool IsNumber(char c);

  void ChangeFilename() noexcept;

  QVector<Texture> tmp_texture_;
  QVector<Vertex> tmp_vertex_;
  QVector<Normal> tmp_normal_;

  QVector<float> data_;
  QVector<unsigned int> indices_;

  QString filename_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_



///data needs to be tied to vertex pointed by single face e.g xyz, txyz, nxyz.
