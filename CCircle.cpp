#include "CCircle.hpp"
#include <sstream>

Circle::Circle(float r) : 
    radius(r) {}
    
float Circle::calculate_area() const 
{
    return 3.14159 * radius * radius;
}

std::string Circle::getRadius() 
{
    std::stringstream ss;
    ss << radius; 
    return (ss.str());
}

std::string Circle::getTag() 
{
    return ("<circle  cx=\"50\" cy=\"50\" r=\" " + getRadius() + "\"/>");
}

