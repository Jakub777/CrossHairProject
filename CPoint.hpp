#ifndef POINT_H
#define POINT_H
#include <string>
class Point
{
public:
    Point(int a, int b);
    int x, y;
    std::string printCoordinates();
};
#endif