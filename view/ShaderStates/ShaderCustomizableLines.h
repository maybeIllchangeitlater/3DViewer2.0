#ifndef CPP4_3DVIEWER_V2_0_VIEW_SHADERSTATES_SHADERCUSTOMIZABLELINES_H_
#define CPP4_3DVIEWER_V2_0_VIEW_SHADERSTATES_SHADERCUSTOMIZABLELINES_H_
#include "ShaderState.h"
namespace s21 {
class ShaderCustomizableLines final : public ShaderState {
 public:
  ShaderCustomizableLines() = default;
  ~ShaderCustomizableLines() override{};
  const char* GetGeometryShader() const noexcept override {
    return ":/resources/GeometryShaderCustomizableLines.txt";
  }
  const char* GetFragmentShader() const noexcept override {
    return ":/resources/FragShader.txt";
  }
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_0_VIEW_SHADERSTATES_SHADERCUSTOMIZABLELINES_H_
