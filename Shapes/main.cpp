#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include <iostream>
#include <vector>

void testRendering(std::vector<Shape*> shapes);

int main() {
    std::vector<Shape*> shapes;

    Rectangle rect({ 50, 100 }, 50, 100, 150, 200, 25, 12);
    Triangle tri({ 1, 2 }, 255, 255, 255, 255, 100, 47);
    Circle circle({ 1000, 2000 }, 39);

    shapes.push_back(&rect);
    shapes.push_back(&tri);
    shapes.push_back(&circle);

    testRendering(shapes);
    std::cin.get();
}

void testRendering(std::vector<Shape*> shapes) {
    for (const auto shape : shapes) {
        shape->Render();
        std::cout << std::endl;
    }
}