#ifndef CPP4_3DVIEWER_V2_0_MODEL_SHADERPOINTSONLY_H_
#define CPP4_3DVIEWER_V2_0_MODEL_SHADERPOINTSONLY_H_
#include "ShaderState.h"
namespace s21{
       class ShaderPointsOnly final : public ShaderState{
       public:
        ShaderPointsOnly() = default;
        ~ShaderPointsOnly() override {};
        const char * GetGeometryShader() override {return ":/resources/GeometryShaderPointsOnly.txt";}
        const char * GetFragmentShader() override {return ":/resources/FragShaderPointsOnly.txt";}
    };
} //namespace s21
#endif //CPP4_3DVIEWER_V2_0_MODEL_SHADERPOINTSONLY_H_
