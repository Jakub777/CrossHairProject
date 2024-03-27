#include "CTriangle.hpp"
#include "CCircle.hpp"

class ShapeMerger
{
public:
    ShapeMerger();
    void calculateFirstVertex (Triangle& triangle, Circle& circle);
    void calculateSecondVertex(Triangle& triangle, Circle& circle);
    void calculateThirdVertex (Triangle& triangle, Circle& circle);
};