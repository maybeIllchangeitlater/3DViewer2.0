#ifndef CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
#define CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
#include <QOpenGLFunctions>
#include <thread>

#include "../model/Affines/CPUTransformation.h"
#include "../model/Affines/GPUTransformation.h"
#include "../model/Affines/TransformationStrategy.h"
#include "../model/parser.h"
#include "../view/settings.h"

namespace s21 {
class Controller : public QObject {
  Q_OBJECT

 public:
  explicit Controller(ObjParser& parser, TransformationStrategy* transformer);
  virtual ~Controller() = default;
  /**
   * @brief Parses file into vertexes and facets
   * @param filename
   */
  void ParseFile(QString filename) const;
  void MoveModel(QMatrix4x4& matrix, const Settings& settings);
  const QVector<unsigned int>& GetFaceConstRef() const noexcept {
    return face_;
  }
  const QVector<float>& GetVertexCopyConstRef() const noexcept {
    return vertex_;
  }
  constexpr const int GetVertexShaderVersion() const noexcept {
    return transformer_->GetShaderVersion();
  }
  const QString GetFilename() const noexcept { return parser_.GetFilename(); }

 signals:
  /**
   * @brief returns signal after file parsing is over
   * @param true - parse success, false - parse fail
   */
  void ParseOver(bool good_file);

 public slots:
  /**
   * @brief recieves signal from parsing thread, updates vertexes and facets
   * @param true - parse success, false - parse fail
   */
  void Update(bool) noexcept;

 private:
  ObjParser& parser_;
  TransformationStrategy* transformer_;
  QVector<float> vertex_;
  QVector<unsigned int> face_;
  QVector<float> vertex_copy_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_CONTROLLER_CONTROLLER_H_
