#ifndef SHAPE_WRITER_H
#define SHAPE_WRITER_H

#include <string>

class ShapeWriter
{
public:
    std::string text;
    std::string newestFileName;
    int WriteToFile();
    int CreateNewFile();
}
#endif