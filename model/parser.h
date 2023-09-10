#ifndef CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_
#define CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_
#include <QDir>
#include <cctype>
namespace s21 {

class ObjParser : public QObject {
  Q_OBJECT

 public:
  void ParseFile();

  const QVector<float>& GetTmpVertexConstRef() const { return tmp_vertex_; }
  const QVector<unsigned int>& GetFaceConstRef() const { return tmp_face_; }
  const QString& GetFilename() const { return filename_; }

  void SetFilename(QString filename) noexcept { filename_ = filename; }

 signals:
  void ParseOver(bool);

 private:
  bool PushVertex(QByteArray& data);
  bool PushFace(QByteArray& data);
  void ChangeFilename() noexcept;

  QVector<float> tmp_vertex_;
  QVector<unsigned int> tmp_face_;
  QString filename_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_MODEL_PARSER_H_
