#ifndef CPP4_3DVIEWER_V2_0_VIEW_SHADERSTATES_SHADERPOINTSONLY_H_
#define CPP4_3DVIEWER_V2_0_VIEW_SHADERSTATES_SHADERPOINTSONLY_H_
#include "ShaderState.h"
namespace s21 {
class ShaderPointsOnly final : public ShaderState {
 public:
  ShaderPointsOnly() = default;
  ~ShaderPointsOnly() override{};
  const char* GetGeometryShader() const noexcept override {
    return ":/resources/GeometryShaderPointsOnly.txt";
  }
  const char* GetFragmentShader() const noexcept override {
    return ":/resources/FragShaderPointsOnly.txt";
  }
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_VIEW_SHADERSTATES_SHADERPOINTSONLY_H_
