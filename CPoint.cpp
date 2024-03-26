#include "CPoint.hpp"
#include <string>
#include <sstream>
Point::Point(int a, int b)
{
    x = a;
    y = b;
}

std::string Point::getPoint()
{
    std::ostringstream s1,s2;
    s1 << x;
    s2 << y;
    return s1.str()+","+s2.str();
}