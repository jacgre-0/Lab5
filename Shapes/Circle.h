#pragma once
#include "Shape.h"

class Circle : public Shape {
public:
    Circle(Point2D point, int radius);
public:
    void Render() override;
private:
    int radius;
};

