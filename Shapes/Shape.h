#pragma once
#include "Point2D.h"
#include <cstdint>

class Shape {
public:
    Shape(Point2D point, uint8_t r, uint8_t g, uint8_t b, uint8_t a);
public:
    uint8_t GetAlpha() const;
    uint8_t GetRed() const;
    uint8_t GetGreen() const;
    uint8_t GetBlue() const;
    Point2D GetPoint() const;
    void SetAlpha(uint8_t value);
    void SetRed(uint8_t value);
    void SetGreen(uint8_t value);
    void SetBlue(uint8_t value);
    void SetPoint(Point2D point);
public:
    virtual void render() = 0;
private:
    Point2D point;
    int color;
};