#pragma once
#include "Shape.h"

class Triangle : public Shape {
public:
    Triangle(Point2D point, uint8_t r, uint8_t g, uint8_t b, uint8_t a, int base, int height);
public:
    void Render() override;
private:
    int base;
    int height;
};

