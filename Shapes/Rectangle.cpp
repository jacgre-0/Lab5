#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(Point2D point, uint8_t r, uint8_t g, uint8_t b, uint8_t a, int width, int height) 
    :
    Shape(point,r,g,b,a),
    width(width),
    height(height)
{}

void Rectangle::Render() {
    std::cout << "Rectangle" << std::endl;
    std::cout << "Position:" << std::endl;
    std::cout << GetPoint().to_string() << std::endl;
    std::cout << "Width: " << width << std::endl;
    std::cout << "Height: " << height << std::endl;
}
