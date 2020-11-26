#pragma once
#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(Point2D point, uint8_t r, uint8_t g, uint8_t b, uint8_t a, int width, int height);
public:
    void Render() override;
private:
    int width;
    int height;
};