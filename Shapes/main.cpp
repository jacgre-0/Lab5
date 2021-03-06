#include "SDL.h"
#include "Shape.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"

#include <iostream>
#include <vector>
#include <random>
#include <optional>


enum class ShapeEnum {Rectangle, Triangle, Circle};

//void testRendering(const std::vector<Shape*>& shapes);
void Update(SDL_Renderer* renderer);
std::optional<int> ProcessInput(const SDL_Event& event, SDL_Renderer* renderer, std::vector<Shape*>& shapes);
void Render(const std::vector<Shape*>& shapes, SDL_Renderer* renderer);
void CreateRandomShape(ShapeEnum shapeToCreate, std::vector<Shape*>& shapes);
 
//task 2 main function
int main(int argc, char** argv) {
    std::vector<Shape*> shapes;

    SDL_Init(SDL_INIT_EVERYTHING);

    SDL_Window* window     = SDL_CreateWindow("Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 500, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    SDL_Event event;

    while (true) {
        SDL_WaitEvent(&event);
        if (ProcessInput(event, renderer, shapes)) {
            //This means we got an exit code so we break the loop and perform the sdl clean up steps
          break;
        }
        else {
            Update(renderer);
            Render(shapes, renderer);
            SDL_RenderPresent(renderer);
        }
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    if (!shapes.empty()) {
        for (auto& shape : shapes) {
            delete shape;
        }
    }
    return 0;
}

void Update(SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
}

//Process some input from the user. If the user press the key "q", the function returns 1, otherwise
//the function returns an empty std::optional (std::nullopt)
std::optional<int> ProcessInput(const SDL_Event& event, SDL_Renderer* renderer, std::vector<Shape*>& shapes) {
    switch (event.type) {
        case SDL_KEYDOWN: {
            switch (event.key.keysym.sym) {
            case SDLK_c:
                CreateRandomShape(ShapeEnum::Circle, shapes);
                break;
            case SDLK_r:
                CreateRandomShape(ShapeEnum::Rectangle, shapes);
                break;
            case SDLK_t:
                CreateRandomShape(ShapeEnum::Triangle, shapes);
                break;
            case SDLK_q:
                return 1;
            case SDLK_x:
                for (auto& shape : shapes) {
                    delete shape;
                }
                shapes.clear();
                break;
            }
        }
    }

    return {};
}

void Render(const std::vector<Shape*>& shapes, SDL_Renderer* renderer) {
    for (const auto shape : shapes) {
        shape->render(renderer);
        std::cout << std::endl;
    }
}

void CreateRandomShape(ShapeEnum shapeToCreate, std::vector<Shape*>& shapes) {
    std::random_device device;
    std::default_random_engine rng(device());

    std::uniform_real_distribution<float> distXCoords(0,650);
    std::uniform_real_distribution<float> distYCoords(0, 450);
    std::uniform_int_distribution<int> distSize(5, 250);

    if (shapeToCreate == ShapeEnum::Circle) {
        auto circ = new Circle({ distXCoords(rng),distYCoords(rng) }, distSize(rng));
        shapes.push_back(circ);
    }
    else if (shapeToCreate == ShapeEnum::Rectangle) {
        auto rect = new Rectangle({ distXCoords(rng),distYCoords(rng) }, 255, 0, 0, 255, distSize(rng), distSize(rng));
        shapes.push_back(rect);
    }
    else if (shapeToCreate == ShapeEnum::Triangle) {
        auto tri = new Triangle({ distXCoords(rng),distYCoords(rng) }, 255, 0, 255, 255, distSize(rng), distSize(rng));
        shapes.push_back(tri);
    }
}

//Task 1 main function
//int main() {
//    std::vector<Shape*> shapes;
//
//    Rectangle rect({ 50, 100 }, 255, 0, 0, 255, 25, 12);
//    Triangle tri({ 1, 2 }, 255, 0, 255, 255, 100, 47);
//    Circle circle({ 100, 200 }, 39);
//
//    shapes.push_back(&rect);
//    shapes.push_back(&tri);
//    shapes.push_back(&circle);
//
//    testRendering(shapes);
//
//    std::cin.get();
//    return 0;
//}
//
//void testRendering(const std::vector<Shape*>& shapes) {
//    for (const auto shape : shapes) {
//        shape->render();
//        std::cout << std::endl;
//    }
//}