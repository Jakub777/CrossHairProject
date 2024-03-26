#include "CShapeMerger.hpp"
#include "CTriangle.hpp"
ShapeMerger::ShapeMerger() {};

void ShapeMerger::calculateFirstVertex(Triangle& triangle, Circle& circle)
{
    int smaller_radius = circle.radius - triangle.height;
    int circle_radius  = circle.radius;
    int outer_offset   = triangle.base * 0.5f;

    if (triangle.orientation == VERTICAL)
    {
        if (triangle.height_direction == RIGHT) {
            triangle.VertexA.x = -smaller_radius;
            triangle.VertexA.y = 0;
        }
        else if (triangle.height_direction == LEFT) {
            triangle.VertexA.x = circle_radius;
            triangle.VertexA.y = outer_offset;
        }
    }
    else if (triangle.orientation == HORIZONTAL)
    {
        if (triangle.height_direction == DOWN) {
            triangle.VertexA.x = outer_offset;
            triangle.VertexA.y = circle_radius;
        }
        else if (triangle.height_direction == UP) {
            triangle.VertexA.x = 0;
            triangle.VertexA.y = -smaller_radius;
        }
    }
}
void ShapeMerger::calculateSecondVertex(Triangle& triangle, Circle& circle)
{
    int smaller_radius = circle.radius - triangle.height;
    int circle_radius  = circle.radius;
    int outer_offset   = triangle.base * 0.5f;

    if (triangle.orientation == VERTICAL)
    {
        if (triangle.height_direction == RIGHT) {
            triangle.VertexB.x = -circle_radius;
            triangle.VertexB.y = -outer_offset;
        }
        else if (triangle.height_direction == LEFT) {
            triangle.VertexB.x = circle_radius;
            triangle.VertexB.y = -outer_offset;
        }
    }
    else if (triangle.orientation == HORIZONTAL)
    {
        if (triangle.height_direction == DOWN) {
            triangle.VertexB.x = 0;
            triangle.VertexB.y = smaller_radius;
        }
        else if (triangle.height_direction == UP) {
            triangle.VertexB.x = outer_offset;
            triangle.VertexB.y = -circle_radius;
        }
    }
}

void ShapeMerger::calculateThirdVertex(Triangle& triangle, Circle& circle)
{
    int smaller_radius = circle.radius - triangle.height;
    int circle_radius  = circle.radius;
    int outer_offset   = triangle.base * 0.5f;

    if (triangle.orientation == VERTICAL)
    {
        if (triangle.height_direction == RIGHT) {
            triangle.VertexC.x = -circle_radius;
            triangle.VertexC.y = outer_offset;
        }
        else if (triangle.height_direction == LEFT) {
            triangle.VertexC.x = smaller_radius;
            triangle.VertexC.y = 0;
        }
    }
    else if (triangle.orientation == HORIZONTAL)
    {
        if (triangle.height_direction == DOWN) {
            triangle.VertexC.x = -outer_offset;
            triangle.VertexC.y = circle_radius;
        }
        else if (triangle.height_direction == UP) {
            triangle.VertexC.x = -outer_offset;
            triangle.VertexC.y = -circle_radius;
        }
    }
}