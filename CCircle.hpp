#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.hpp"

class Circle : 
    public Shape 
{
public:
    float radius;

    Circle(float r);
    float calculate_area() const override;
    // float get_radius() const;
};
#endif
