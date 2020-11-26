#include "Circle.h"
#include <iostream>

Circle::Circle(Point2D point, int radius) 
    :
    Shape(point, 0u,0u,0u,1u),
    radius(radius)
{}

int Circle::GetRadius() const {
    return radius;
}

void Circle::SetRadius(int value) {
    if (value < 0) {
        std::cout << "Radius cannot be negative!" << std::endl;
        return;
    }
    radius = value;
}

void Circle::render() {
    std::cout << "Circle" << std::endl;
    std::cout << "Position:" << std::endl;
    std::cout << GetPoint().to_string() << std::endl;
    std::cout << "Radius: " << radius << std::endl;
}
