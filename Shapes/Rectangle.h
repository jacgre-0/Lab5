#pragma once
#include "Shape.h"

class Rectangle : public Shape {
public:
    Rectangle(Point2D point, uint8_t r, uint8_t g, uint8_t b, uint8_t a, int width, int height);
public:
    int GetWidth() const;
    int GetHeight() const;
    void SetWidth(int value);
    void SetHeight(int value);
public:
    void render() override;
private:
    int width;
    int height;
};