#pragma once
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "RNG.h"
#include <vector>
#include <string>
#include <cstdlib>
#include <semaphore>

void CreateRectangle(std::vector <Rectangle>&);
void CreateTriangle(std::vector <Triangle>&);
void CreateCircle(std::vector <Circle>&);
void CreateShape(std::vector <Shape>&);


int length;
int width;
int radius;
int height;
