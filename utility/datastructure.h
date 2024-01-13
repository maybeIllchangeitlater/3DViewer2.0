#ifndef CPP4_3DVIEWER_V_2_1_UTILITY_DATASTRUCTURE_H
#define CPP4_3DVIEWER_V_2_1_UTILITY_DATASTRUCTURE_H

#include <cstddef>
#include <stdexcept>
#include <vector>

namespace s21{
    constexpr static const short OBJECT_PROPERTIES_COUNT = 8;
    struct Texture{
        float x;
        float y;
        float& operator[](size_t index){
            if(index == 0) return x;
            if(index == 1) return y;
            throw std::out_of_range("out of structure bounds");
        }
    };
    struct Vertex : public Texture{
        float z;
        float& operator[](size_t index){
            if(index == 0) return x;
            if(index == 1) return y;
            if(index == 2) return z;
            throw std::out_of_range("out of structure bounds");
        }
        void operator*=(float num){
            x *= num;
            y *= num;
            z *= num;
        }
    };
    using Normal = Vertex;

} //s21

#endif //CPP4_3DVIEWER_V_2_1_UTILITY_DATASTRUCTURE_H
