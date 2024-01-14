#ifndef CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_
#define CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_

#include <QDir>
#include <cctype>
#include <limits>
#include <vector>
#include "../utility/earcutting.h"
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
  short GetObjectPropertiesCount() const noexcept { return object_properties_count_; }
  const QString &GetFilename() const noexcept { return filename_; }

  void SetFilename(QString filename) noexcept { filename_ = filename; }

 signals:
  void ParseOver(bool);

 private:
  /**
   * @brief Check if file contains textures and normales
   */
  void ParseFlags(QFile &file);
  /**
   * @brief Add point (vertex, texture or normal) from file to corresponding container
   */
  template<typename Coordinatable>
  bool PushPoint(QByteArray& data, Coordinatable &target);
  /**
   * @brief Add vertexes, textures and normales to vertex data vector during facet parsing
   */
  bool ParseFace(QByteArray& data);
  /**
   * @brief Adds initial 0 values to each container
   */
  void AddZeros();

  /**
   * @brief Add point (vertex, texture or normal) from corresponding container to vertices data
   */
  template<typename Coordinatable>
  bool ToVerticeData(char *&data, Coordinatable &from);

  void Clear();
  /**
   * @brief SkipUntilNextDigit. used to get to vertex coordinates
   */
  static void SkipUntilNextDigit(char *&data) noexcept;
  /**
   * @brief SkipUntilNextFace. get to \ or ' '
   */
  static void SkipUntilNextFace(char *&data) noexcept;
  /**
   * @brief if texture exists in file and facet returns true. if it exist in file but not found in face adds default values 000
   */
  static void SkipWhitespaces(char *&data) noexcept;
  bool CheckTexture(char *&data);
  bool CheckNormale(char *&data);
  /**
   * @brief triangulates polygon (with terrible memory and speed complexity, oh well. extra 1800 lines of code can wait for another time)
   */
  void FakeTriangulate(QVector<float>& first, QVector<float> &middle, size_t &counter);

  static bool IsNumber(char c) noexcept;
  static bool LineOver(char c) noexcept;

  void ChangeFilename() ;

  QVector<Texture> tmp_texture_;
  QVector<Vertex> tmp_vertex_;
  QVector<Normal> tmp_normal_;
  QVector<float> tmp_vertices_;

  QVector<float> data_;
  QVector<unsigned int> indices_;

  QString filename_;
  short object_properties_count_;
  bool has_normales_;
  bool has_textures_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_



///data needs to be tied to vertex pointed by single face e.g xyz, txyz, nxyz.
