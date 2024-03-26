#ifndef SHAPE_WRITER_H
#define SHAPE_WRITER_H

#include <string>
#include "IShape.hpp"

class ShapeWriter
{
public:
    std::string text;
    std::string newestFileName;
    int WriteToFile();
    int CreateNewFile();
    void CreateTagFromShape(Shape* shape);
};
#endif