#ifndef CPP4_3DVIEWER_V2_0_MODEL_SHADERSTATE_H_
#define CPP4_3DVIEWER_V2_0_MODEL_SHADERSTATE_H_

namespace s21{
    class ShaderState{
    public:
        ShaderState() = default;
        virtual ~ShaderState() = default;
        /**
         * @brief GetVertexShader
         * @param version 1 - for GPU transformations, 2 - for CPU transformations
         */
        inline const char * GetVertexShader(int version) {return version == 1 ? ":/resources/VertexShader.txt" : ":/resources/VertexShaderCPU.txt";};
        virtual const char * GetGeometryShader() = 0;
        virtual const char * GetFragmentShader() = 0;

    };
} //namespace s21

#endif //CPP4_3DVIEWER_V2_0_MODEL_SHADERSTATE_H_
