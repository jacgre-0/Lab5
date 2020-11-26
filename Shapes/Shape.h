#pragma once
#include <cstdint>

class Shape {
public:
    Shape(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
public:
    uint8_t GetAlpha() const;
    uint8_t GetRed() const;
    uint8_t GetGreen() const;
    uint8_t GetBlue() const;
    void SetAlpha(uint8_t value);
    void SetRed(uint8_t value);
    void SetGreen(uint8_t value);
    void SetBlue(uint8_t value);
    virtual void Render() {};
private:
    int color;
};