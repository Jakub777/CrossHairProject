#include "CShapeWriter.hpp"
#include "CCircle.hpp"
#include "CTriangle.hpp"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <sstream>

int ShapeWriter::CreateNewFile() {
    std::string crosshairName = "Crosshair";
    std::string fileExtension = ".svg";
    std::stringstream combinedName;
    std::string newName;
    const int MAX_CROSSHAIR_NUMBER = 1000;
    int i = 0;
    for (i = 0; i < MAX_CROSSHAIR_NUMBER; i++)
    {
        combinedName << crosshairName << i << fileExtension;
        newName = combinedName.str();
        combinedName.str(std::string());
        
        std::cout << newName << std::endl;;

        if (!std::filesystem::exists(newName))
            break;           
    }
    if (i == MAX_CROSSHAIR_NUMBER - 1 ) {
        std::cout << "No more free names";
        return -2;
    }
    std::ofstream new_file(newName);
    if (new_file.is_open()) 
    {
        newestFileName = newName;
        std::cout << "File was created.\n";
        new_file.close();
    }
    else 
    {
        std::cout << "File creation error.\n";
        return -1;
    }
    return 0;
}

int ShapeWriter::WriteToFile()
{
    std::ofstream current_file(newestFileName);
    if (current_file.is_open()) 
    {
        current_file << text;
        current_file.close(); // Zamykanie pliku
    } 
    else 
    {
        std::cout << "Blad podczas zapisywania do pliku.\n";
        return -1;
    }
    return 0;
}

void ShapeWriter::CreateTagFromShape(Shape* shape)
{
    std::stringstream ss;
    ss << "<";
    if (Circle* circle = dynamic_cast<Circle*>(shape))
    {
        ss << "circle  cx=\"50\" cy=\"50\" r=\"" << circle->radius << "\"";
    }
    else if (Triangle* triangle = dynamic_cast<Triangle*>(shape))
    {
        ss << "polygon points=\""  << triangle->VertexA.printCoordinates() << " "
                                    << triangle->VertexB.printCoordinates() << " "
                                    << triangle->VertexC.printCoordinates() << "\"";
    }
    ss << " fill=\"red\" />\n";
    text = ss.str();
}