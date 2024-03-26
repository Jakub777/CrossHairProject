#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "IShape.hpp"
#include "CPoint.hpp"
#include <string>

enum Orientation{
    HORIZONTAL,
    VERTICAL
};

enum HeightDirection{
    LEFT,
    UP,
    RIGHT,
    DOWN
};

class Triangle :
    public Shape
{
public:
    float base;
    float height;
    Orientation orientation;
    HeightDirection height_direction;
    // consider adding decorator for vertex calc in future
    Point VertexA;
    Point VertexB;
    Point VertexC;

    Triangle(Orientation o, HeightDirection h, float a, float b);
    float calculate_area() const override;
    std::string getTag() override;
};
#endif