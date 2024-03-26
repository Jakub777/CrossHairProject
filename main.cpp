#include <iostream>
#include "CTriangle.hpp"
#include "CCircle.hpp"
#include "CShapeMerger.hpp"
#include "CShapeWriter.hpp"
#include <vector>
int main()
{
    std::vector<Triangle> MyTriangles;
    MyTriangles.push_back(Triangle(HORIZONTAL, DOWN,   20,  40));
    MyTriangles.push_back(Triangle(VERTICAL,   LEFT,   20,  40));
    MyTriangles.push_back(Triangle(HORIZONTAL, UP,     20,  40));
    MyTriangles.push_back(Triangle(VERTICAL,   RIGHT,  20,  40));
    Circle MyCircle(45);
    ShapeMerger MyMerger;
    ShapeWriter MyWriter;

    std::vector<std::string> MyColors = {"red", "blue", "green", "black"};
    int i = 0;
    for (auto triangle : MyTriangles)
    {
        MyMerger.calculateFirstVertex(triangle, MyCircle);
        MyMerger.calculateSecondVertex(triangle, MyCircle);
        MyMerger.calculateThirdVertex(triangle, MyCircle);
        std::cout << "new point " << triangle.VertexA.getPoint() << std::endl;  
    }
    for (auto triangle : MyTriangles)
    {
        std::cout << "one more time " << triangle.VertexA.getPoint() << std::endl;  
    }
    MyWriter.CreateNewFile();
    MyWriter.CreateStartTag();
    MyWriter.CreateTagFromShape(&MyTriangles.at(1));
    MyWriter.CreateExitTag();
    MyWriter.WriteToFile();
    std::cin.get();
    return 0;
}