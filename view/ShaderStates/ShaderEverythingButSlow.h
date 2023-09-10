#ifndef CPP4_3DVIEWER_V2_0_VIEW_SHADERSTATES_SHADEREVERYTHINGBUTSLOW_H_
#define CPP4_3DVIEWER_V2_0_VIEW_SHADERSTATES_SHADEREVERYTHINGBUTSLOW_H_
#include "ShaderState.h"
namespace s21 {
class ShaderEverythingButSlow final : public ShaderState {
 public:
  ShaderEverythingButSlow() = default;
  ~ShaderEverythingButSlow() override{};
  const char* GetGeometryShader() const noexcept override {
    return ":/resources/GeometryShader.txt";
  }
  const char* GetFragmentShader() const noexcept override {
    return ":/resources/FragShader.txt";
  }
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_VIEW_SHADERSTATES_SHADEREVERYTHINGBUTSLOW_H_
