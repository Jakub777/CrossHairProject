#include <iostream>
#include "CTriangle.hpp"
#include "CCircle.hpp"
#include "CShapeMerger.hpp"
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

    std::vector<std::string> MyColors = {"red", "blue", "green", "black"};
    int i = 0;
    for (auto triangle : MyTriangles)
    {
        MyMerger.calculateFirstVertex(triangle, MyCircle);
        MyMerger.calculateSecondVertex(triangle, MyCircle);
        MyMerger.calculateThirdVertex(triangle, MyCircle);
        std::cout << "<polygon points=\"";
        std::cout << triangle.VertexA.printCoordinates() << " ";
        std::cout << triangle.VertexC.printCoordinates() << " ";
        std::cout << triangle.VertexB.printCoordinates()<< "\" fill=\""<<MyColors.at(i++)<<"\" />\n";
    }
    return 0;
}