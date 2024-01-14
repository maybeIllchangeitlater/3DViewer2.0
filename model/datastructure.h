#ifndef CPP4_3DVIEWER_V_2_1_UTILITY_DATASTRUCTURE_H
#define CPP4_3DVIEWER_V_2_1_UTILITY_DATASTRUCTURE_H

#include <cstddef>
#include <stdexcept>
#include <vector>

namespace s21{
    constexpr static const short DEFAULT_OBJECT_PROPERTIES_COUNT = 8;
    constexpr static const short VERTEX_PROPERTIES_SIZE = 3;
    constexpr static const short TEXTURE_PROPERTIES_SIZE = 2;
    constexpr static const short NORMALE_PROPERTIES_SIZE = 3;
    struct Texture{
        float x;
        float y;
        float z;
        float garbage;
        float& operator[](size_t index){
            if(index == 0) return x;
            if(index == 1) return y;
            if(index == 2) return z;
            return garbage;
        }

    };
    struct Vertex : public Texture{
        void operator*=(float num){
            x *= num;
            y *= num;
            z *= num;
        }
    };


    using Normal = Vertex;

} //s21

#endif //CPP4_3DVIEWER_V_2_1_UTILITY_DATASTRUCTURE_H
