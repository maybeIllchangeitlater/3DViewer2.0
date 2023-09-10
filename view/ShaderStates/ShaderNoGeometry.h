#ifndef CPP4_3DVIEWER_V2_0_VIEW_SHADERSTATES_SHADERNOGEOMETRY_H_
#define CPP4_3DVIEWER_V2_0_VIEW_SHADERSTATES_SHADERNOGEOMETRY_H_
#include "ShaderState.h"
namespace s21 {
class ShaderNoGeometry final : public ShaderState {
 public:
  ShaderNoGeometry() = default;
  ~ShaderNoGeometry() override{};
  const char* GetGeometryShader() const noexcept override { return nullptr; }
  const char* GetFragmentShader() const noexcept override {
    return ":/resources/FragShaderNoGeometry.txt";
  }
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_VIEW_SHADERSTATES_SHADERNOGEOMETRY_H_
