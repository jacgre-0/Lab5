#include "Triangle.h"
#include <iostream>

Triangle::Triangle(Point2D point, uint8_t r, uint8_t g, uint8_t b, uint8_t a, int base, int height)
    :
    Shape(point,r,g,b,a),
    base(base),
    height(height)
{
}

void Triangle::Render() {
    std::cout << "Triangle" << std::endl;
    std::cout << "Position:" << std::endl;
    std::cout << GetPoint().to_string() << std::endl;
    std::cout << "Base: " << base << std::endl;
    std::cout << "Height: " << height << std::endl;
}
