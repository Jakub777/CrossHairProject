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
    void CreateStartTag();
    void CreateExitTag();
};
#endif

//<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"-50 -50 100 100\">