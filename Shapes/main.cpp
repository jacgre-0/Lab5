#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include <iostream>
#include <vector>
#include "SDL.h"

void testRendering(std::vector<Shape*> shapes, SDL_Renderer* renderer);

int main(int argc, char* argv[]) {
    //set up sdl
    SDL_Init(SDL_INIT_EVERYTHING);

    //create the window and renderer
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_CreateWindowAndRenderer(800, 500, SDL_WINDOW_SHOWN, &window, &renderer);
   
    //Set the clear color
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
   
    std::vector<Shape*> shapes;

    Rectangle rect({ 50, 100 }, 255, 0, 0, 255, 25, 12);
    Triangle tri({ 1, 2 }, 255, 0, 255, 255, 100, 47);
    Circle circle({ 100, 200 }, 39);

    shapes.push_back(&rect);
    shapes.push_back(&tri);
    shapes.push_back(&circle);

    testRendering(shapes,renderer);

    SDL_RenderPresent(renderer);
    SDL_Delay(5000);

    //quit and clean up
    SDL_DestroyWindow(window);
    SDL_Quit();

    std::cin.get();
    return 0;
}

void testRendering(std::vector<Shape*> shapes, SDL_Renderer* renderer) {
    for (const auto shape : shapes) {
        shape->render(renderer);
        std::cout << std::endl;
    }
}