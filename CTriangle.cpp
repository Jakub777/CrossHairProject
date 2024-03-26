#include "CTriangle.hpp"
#include <iostream>
#include <string>

Triangle::Triangle(Orientation o, HeightDirection h, float a, float b) :
    VertexA(1,1),
    VertexB(2,2),
    VertexC(3,3),
    orientation(o),
    height_direction(h),
    base(a),
    height(b) {}

float Triangle::calculate_area() const {
    return 0,5 * base * height;
}

std::string Triangle::getTag() {
    return ("<polygon points=\""  +
    VertexA.getPoint() + " "+
    VertexB.getPoint() + " "+
    VertexC.getPoint() + "\"/>");
}