#include <iostream>
#include "CTriangle.hpp"
#include "CCircle.hpp"
#include "CShapeMerger.hpp"
#include "CShapeWriter.hpp"
#include <vector>
int main()
{
    Circle MyCircle(45);
    std::vector<Triangle> MyTriangles;

    MyTriangles.push_back(Triangle(HORIZONTAL, DOWN,   20,  40));
    MyTriangles.push_back(Triangle(VERTICAL,   LEFT,   20,  40));
    MyTriangles.push_back(Triangle(HORIZONTAL, UP,     20,  40));
    MyTriangles.push_back(Triangle(VERTICAL,   RIGHT,  20,  40));
    
    ShapeMerger MyMerger;
    ShapeWriter MyWriter;

    std::vector<std::string> MyColors = {"red", "blue", "green", "black"};

    for (auto& triangle : MyTriangles) {
        MyMerger.calculateFirstVertex(triangle, MyCircle);
        MyMerger.calculateSecondVertex(triangle, MyCircle);
        MyMerger.calculateThirdVertex(triangle, MyCircle);
    }

    MyWriter.CreateNewFile();
    MyWriter.CreateStartTag();
    for (auto& triangle : MyTriangles)
        MyWriter.CreateTagFromShape(triangle);
    MyWriter.CreateExitTag();
    MyWriter.WriteToFile();
    std::cin.get();
    return 0;
}