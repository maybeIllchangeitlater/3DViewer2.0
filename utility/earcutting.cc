#include "earcutting.h"

namespace s21 {


std::vector<float> EarCutting::CutEars()
{
    std::vector<float> triangled;
    while(polygon_raw_.size() > 3 * object_properties_count){
        bool ear_clipped = false;
        for(auto iter = polygon_raw_.begin(); iter != polygon_raw_.end(); iter+=object_properties_count){
            if(IsEar(iter)){
                ear_clipped = true;
                auto ear_iter = iter;
                if(iter == polygon_raw_.begin()){
                    auto previous = polygon_raw_.end() - object_properties_count;
                    for(size_t i = 0; i < object_properties_count; ++i){
                        triangled.emplace_back(*previous++);
                    }
                    for(size_t i = 0; i < object_properties_count * 2; ++i){
                        triangled.emplace_back(*iter++);
                    }
                }else{
                    if(iter == polygon_raw_.end() - object_properties_count){
                        for(size_t i = 0; i < object_properties_count * 3; ++i){
                            triangled.emplace_back(*iter++);
                        }
                    }
                }
                polygon_raw_.erase(ear_iter, ear_iter + object_properties_count);
                break;
            }
        }
        if(!ear_clipped){
            ClipMinimalAngle();
        }
    }

    triangled.insert(triangled.end(), polygon_raw_.begin(), polygon_raw_.end());

    while(triangled.size() < 3 * object_properties_count){
        triangled.insert(triangled.begin(), triangled.begin(), triangled.begin() + object_properties_count);
    }

    return triangled;
}

bool EarCutting::IsEar(std::vector<float>::iterator &point)
{
    auto [previous, current, next] = GetPreviousCurrentNext(point);

    bool counterclockwise =
            VerticesPositionedCounterClockWise(previous, current, next);

    auto previous_iter = point == polygon_raw_.begin()
            ? polygon_raw_.end() - object_properties_count
            : point - object_properties_count;
    auto next_iter = point == polygon_raw_.end() - 1
            ? polygon_raw_.begin()
            : point + object_properties_count;

    // Check that there are no other vertices inside the triangle
    for (auto iter = polygon_raw_.begin(); iter != polygon_raw_.end(); iter+=object_properties_count) {
        if (iter != point && iter != previous_iter && iter != next_iter) {
            Vertex p{*iter, *(iter + 1), *(iter + 2)};
            if(PointIsInsideTriangle(p, previous, current, next, counterclockwise)){
                return false;
            }
        }
    }
    return true;
}

std::tuple<Vertex, Vertex, Vertex> EarCutting::
    GetPreviousCurrentNext(std::vector<float>::iterator &point) const
{
    Vertex current{*point, *(point + 1), *(point + 2)};
    Vertex previous;
    Vertex next;
    if(point != polygon_raw_.begin()){
        previous = {*(point - object_properties_count),
                        *(point - object_properties_count + 1),
                    *(point - object_properties_count + 2)};
    }else{
        previous = {*(polygon_raw_.end() - object_properties_count),
                    *(polygon_raw_.end() - object_properties_count + 1),
                    *(polygon_raw_.end() - object_properties_count + 2)};
    }
    if(point != polygon_raw_.end() - object_properties_count){
            next = {*(point + object_properties_count),
                            *(point + object_properties_count + 1),
                    *(point + object_properties_count + 2)};
        }else{
            next = {*(polygon_raw_.begin()),
                        *(polygon_raw_.begin() + 1),
                    *(polygon_raw_.begin() + 2)};
        }

    return std::make_tuple(std::move(previous), std::move(current), std::move(next));
}

bool EarCutting::VerticesPositionedCounterClockWise(
        Vertex &previous, Vertex &current, Vertex &next) const{
    double cross_product
            = CrossProduct(std::make_pair(previous.x, previous.y),
                           std::make_pair(current.x, current.y),
                           std::make_pair(next.x, next.y));
    if(cross_product >= 0){
        std::swap(previous, next);
        return false;
    }
    return true;
}

bool EarCutting::PointIsInsideTriangle(const Vertex &p, const Vertex &previous,
                                       const Vertex &current, const Vertex &next, bool counterclockwise) const{
    double cross_product1 =
        CrossProduct(std::make_pair(previous.x, previous.y),
                     std::make_pair(current.x, current.y),
                     std::make_pair(p.x, p.y));
    double cross_product2 =
        CrossProduct(std::make_pair(previous.x, previous.y),
                     std::make_pair(p.x, p.y),
                     std::make_pair(next.x, next.y));
    double cross_product3 =
        CrossProduct(std::make_pair(p.x, p.y),
                     std::make_pair(current.x, current.y),
                     std::make_pair(next.x, next.y));
    double cross_product4 =
        CrossProduct(std::make_pair(previous.x, previous.z),
                     std::make_pair(current.x, current.z),
                     std::make_pair(p.x, p.z));
    double cross_product5 =
        CrossProduct(std::make_pair(previous.x, previous.z),
                     std::make_pair(p.x, p.z),
                     std::make_pair(next.x, next.z));
    double cross_product6 =
        CrossProduct(std::make_pair(p.x, p.z),
                     std::make_pair(current.x, current.z),
                     std::make_pair(next.x, next.z));
    if (counterclockwise && cross_product1 >= 0 && cross_product2 >= 0 && cross_product3 >= 0
        && cross_product4 >= 0 && cross_product5 >= 0 && cross_product6 >= 0) {
        return true;
    }else if (!counterclockwise && cross_product1 <= 0 && cross_product2 <= 0 && cross_product3 <= 0
            && cross_product4 <= 0 && cross_product5 <= 0 && cross_product6 <= 0) {
        return true;
    }
    return false;
}

void EarCutting::ClipMinimalAngle()
{
    double minimal_angle = std::numeric_limits<double>::max();
    double current_angle;
    auto minimal_angle_iter = polygon_raw_.begin();
    for(auto iter = polygon_raw_.begin(); iter != polygon_raw_.end();
        iter+=object_properties_count){
        current_angle = CalculateAngle(iter);
        if(minimal_angle > current_angle){
            minimal_angle = current_angle;
            minimal_angle_iter = iter;
        }
    }
    polygon_raw_.erase(minimal_angle_iter,
                      minimal_angle_iter + object_properties_count);
}

double EarCutting::CalculateAngle(std::vector<float>::iterator &point) const
{
    auto [previous, current, next] = GetPreviousCurrentNext(point);

    //vectors p-c and c-n
    double pc_x = current.x - previous.x;
    double pc_y = current.y - previous.y;
    double cn_x = next.x - current.x;
    double cn_y = next.y - current.y;

    double dot = pc_x * cn_x + pc_y * cn_y;
    double cross = pc_x * cn_y - pc_y * cn_x;

    //in radians
    return std::atan2(cross, dot);
}


} // namespace s21

/*
 * std::vector<Triangle> triangulatePolygonWithHoles(const std::vector<Point>& outerBoundary, const std::vector<std::vector<Point>>& holes) {
            std::vector<Triangle> triangles;

            // Triangulate the outer boundary
            std::vector<Triangle> outerTriangles = earCut(outerBoundary);
            triangles.insert(triangles.end(), outerTriangles.begin(), outerTriangles.end());

            // Triangulate each hole separately
            for (const auto& hole : holes) {
                std::vector<Triangle> holeTriangles = earCut(hole);
                triangles.insert(triangles.end(), holeTriangles.begin(), holeTriangles.end());

                // Connect the edges of the outer boundary with the hole
                connectBoundaryWithHole(outerBoundary, hole, triangles);
            }

            return triangles;
        }

        std::vector<Triangle> earCut(const std::vector<Point>& polygon) {
            // Existing implementation of the Ear Cutting algorithm for a simple polygon
            // ...
        }

        void connectBoundaryWithHole(const std::vector<Point>& outerBoundary, const std::vector<Point>& hole, std::vector<Triangle>& triangles) {
            // Find the closest vertex on the hole to each edge of the outer boundary
            for (size_t i = 0; i < outerBoundary.size(); ++i) {
                const Point& edgeStart = outerBoundary[i];
                const Point& edgeEnd = outerBoundary[(i + 1) % outerBoundary.size()];

                Point closestVertex = findClosestVertex(edgeStart, edgeEnd, hole);

                // Create new triangles connecting the edge of the outer boundary with the hole
                triangles.push_back(Triangle(edgeStart, edgeEnd, closestVertex));
            }
        }

        Point findClosestVertex(const Point& start, const Point& end, const std::vector<Point>& vertices) {
            Point closestVertex = vertices[0];
            double minDistance = distance(start, closestVertex);

            for (size_t i = 1; i < vertices.size(); ++i) {
                double distanceToEdge = distanceToLineSegment(start, end, vertices[i]);
                if (distanceToEdge < minDistance) {
                    minDistance = distanceToEdge;
                    closestVertex = vertices[i];
                }
            }

            return closestVertex;
        }

        double distance(const Point& p1, const Point& p2) {
            double dx = p2.x - p1.x;
            double dy = p2.y - p1.y;
            return std::sqrt(dx * dx + dy * dy);
        }

        double distanceToLineSegment(const Point& start, const Point& end, const Point& point) {
            double dx = end.x - start.x;
            double dy = end.y - start.y;
            double lengthSquared = dx * dx + dy * dy;

            if (lengthSquared == 0.0) {
                return distance(point, start);
            }

            double t = std::max(0.0, std::min(1.0, dotProduct(point - start, end - start) / lengthSquared));
            Point projection = start + (end - start) * t;

            return distance(point, projection);
        }

        double dotProduct(const Point& p1, const Point& p2) {
            return p1.x * p2.x + p1.y * p2.y;
        }

*/
