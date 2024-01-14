#ifndef CPP4_3DVIEWER_V2_0_MODEL_EARCUTTING_H
#define CPP4_3DVIEWER_V2_0_MODEL_EARCUTTING_H

#include "datastructure.h"
#include <vector>


namespace s21 {

class EarCutting
{
public:
    std::vector<float> CutEars();
    void Clear() { polygon_raw_.clear(); }
    std::vector<float> &GetPolygon() noexcept { return polygon_raw_; }
    short &GetObjectPropertiesCount() noexcept { return object_properties_count; }
private:
    bool IsEar(std::vector<float>::iterator &point);
    std::tuple<Vertex, Vertex, Vertex> GetPreviousCurrentNext(
            std::vector<float>::iterator &point) const;
    double CrossProduct(const std::pair<float, float> p1,
                        const std::pair<float, float> p2,
                        const std::pair<float, float> p3) const noexcept{
        return (p2.first - p1.first) * (p3.second - p2.second)
                - (p3.first - p2.first) * (p2.second - p1.second);
    }
    bool VerticesPositionedCounterClockWise(Vertex &previous,
                                            Vertex &current, Vertex &next) const;;
    bool PointIsInsideTriangle(const Vertex &p, const Vertex &previous,
                               const Vertex &current, const Vertex &next,
                               bool counterclockwise) const;
    void ClipMinimalAngle();
    double CalculateAngle(std::vector<float>::iterator &point) const;

    std::vector<float> polygon_raw_;
    short object_properties_count;
};

} // s21

#endif // CPP4_3DVIEWER_V2_0_MODEL_
