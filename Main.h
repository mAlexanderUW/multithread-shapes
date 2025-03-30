#pragma once
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib>
#include <thread>
#include <semaphore>


void RandomNumbers();
void Finished();

void CreateRectangles(std::vector <Shape*>&, int);
void CreateTriangles(std::vector <Shape*>&, int);
void CreateCircles(std::vector <Shape*>&, int);
void CreateShapes(std::vector <Shape*>&, int);

void ChangeShapesTo3D(std::vector <Shape*>&);
void PrintShapes(std::vector <Shape*>&);
void TallyTotals(std::vector <Shape*>&);
void DisplayTotals();

std::binary_semaphore
sendLock{ 1 },
recieveLock{ 0 },
displayLock{ 1 };

int length;
int width;
int radius;
int height;
int randomNumber;
int totalRectangles;
int totalTriangles;
int totalCircles;
float totalArea;
float totalVolume;

bool needValue = true;