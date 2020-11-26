#pragma once
#include "Shape.h"

class Circle : public Shape {
public:
    Circle(Point2D point, int radius);
public:
    int GetRadius() const;
    void SetRadius(int value);
public:
    void render() override;
private:
    int radius;
};

