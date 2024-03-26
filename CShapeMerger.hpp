#include "CTriangle.hpp"
#include "CCircle.hpp"

class ShapeMerger
{
public:
    // if a funcion that need more then 1 argument of each type you will need to make more refs
    Triangle& triangle;
    Circle& circle;
    ShapeMerger();
    void calculateFirstVertex (Triangle& triangle, Circle& circle);
    void calculateSecondVertex(Triangle& triangle, Circle& circle);
    void calculateThirdVertex (Triangle& triangle, Circle& circle);
};