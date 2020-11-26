#include "Circle.h"
#include <iostream>

Circle::Circle(Point2D point, int radius) 
    :
    Shape(point, 0u,0u,0u,1u),
    radius(radius)
{}

void Circle::Render() {
    std::cout << "Circle" << std::endl;
    std::cout << "Position:" << std::endl;
    std::cout << GetPoint().to_string() << std::endl;
    std::cout << "Radius: " << radius << std::endl;
}
