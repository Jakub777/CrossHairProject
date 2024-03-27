#include <iostream>
#include "CTriangle.hpp"
#include "CCircle.hpp"
#include "CShapeMerger.hpp"
#include "CShapeWriter.hpp"
#include <vector>
#include <SFML/Graphics.hpp>

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
    for (auto triangle : MyTriangles)
        MyWriter.CreateTagFromShape(&triangle);
    MyWriter.CreateExitTag();
    MyWriter.WriteToFile();



    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    std::cin.get();
    return 0;
}