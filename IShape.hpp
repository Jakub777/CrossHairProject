#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

class Shape {
public:
    // Pure virtual function to calculate area
    virtual float calculate_area() const = 0;
    virtual std::string getTag() = 0;
    
    // Virtual destructor
    virtual ~Shape() {}
};

#endif