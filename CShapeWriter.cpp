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
    std::string path = "Crosshairs/";
    const int MAX_CROSSHAIR_NUMBER = 1000;
    int i = 0;

    for (i = 0; i < MAX_CROSSHAIR_NUMBER; i++)
    {
        combinedName << path << crosshairName << i << fileExtension;
        newName = combinedName.str();

        if (!std::filesystem::exists(newName))
            break;               
        combinedName.str(std::string());
    }
    if (i == MAX_CROSSHAIR_NUMBER - 1 ) {
        std::cout << "No more free names";
        return -2;
    }
    std::cout << "New file name: " << newName << std::endl;

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
    text.append(shape->getTag()+"\n");
}

void ShapeWriter::CreateStartTag()
{
    std::string startingLine = "<svg xmlns=\"http://www.w3.org/2000/svg\" viewBox=\"-50 -50 100 100\">\n";
    text.append (startingLine);
}
void ShapeWriter::CreateExitTag()
{
    std::string endingLine = "</svg>";
    text.append(endingLine);
}