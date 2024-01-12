#ifndef CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_
#define CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_

#include <QDir>
#include <cctype>
#include "../utility/datastructure.h"

namespace s21 {

class ObjParser : public QObject {
  Q_OBJECT

 public:
  void ParseFile();

  const QVector<VerticeData> &GetVerticesDataConstRef() const noexcept { return vertices_data_; }
  const QVector<unsigned int> &GetFaceConstRef() const noexcept { return tmp_face_vertex_; }
  const QString& GetFilename() const noexcept { return filename_; }

  void SetFilename(QString filename) noexcept { filename_ = filename; }

 signals:
  void ParseOver(bool);

 private:
  template<typename Coordinatable>
  bool PushPoint(QByteArray& data, Coordinatable &target);
  bool PushFace(QByteArray& data);

  void CombineData();

  void SkipUntilNextDigit(size_t &index, size_t data_size, char * data);
  void SkipUntilNextFace(size_t &index, size_t data_size, char * data);
  void ChangeFilename() noexcept;

  QVector<float> tmp_texture_;
  QVector<Normal> tmp_normal_;
  QVector<unsigned int> tmp_face_vertex_;
  QVector<unsigned int> tmp_face_texture_;
  QVector<unsigned int> tmp_face_normal_;
  QVector<VerticeData> vertices_data_;
  QString filename_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_



///data needs to be tied to vertex pointed by single face e.g xyz, txyz, nxyz.
