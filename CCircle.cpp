#include "CCircle.hpp"

Circle::Circle(float r) : 
    radius(r) {}
float Circle::calculate_area() const 
{
    return 3.14159 * radius * radius;
}
