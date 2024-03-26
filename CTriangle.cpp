#include "CTriangle.hpp"
#include <iostream>
#include <string>

Triangle::Triangle(Orientation o, HeightDirection h, float a, float b) :
    VertexA(0,0),
    VertexB(0,0),
    VertexC(0,0),
    orientation(o),
    height_direction(h),
    base(a),
    height(b) {
    }

float Triangle::calculate_area() const {
    return 0,5 * base * height;
}

std::string Triangle::writeSVGformula() {
    return "dupa" ;
}
