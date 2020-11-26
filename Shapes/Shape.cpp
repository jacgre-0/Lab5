#include "Shape.h"

Shape::Shape(uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
    color = a << 24 | r << 16 | g << 8 | b;
}

uint8_t Shape::GetAlpha() const {
    return (color >> 24) & 0xFF;
}

uint8_t Shape::GetRed() const {
    return (color >> 16) & 0xFF;
}

uint8_t Shape::GetGreen() const {
    return (color >> 8) & 0xFF;
}

uint8_t Shape::GetBlue() const {
    return color & 0xFF;
}
