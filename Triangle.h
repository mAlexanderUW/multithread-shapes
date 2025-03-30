#pragma once
#include "Shape.h"

class Triangle : public Shape
{
public:
	Triangle(int, int);
	float getArea() override;
	float getVolume() override;
	std::string getShape() override;
	void Print() override;

private:
	int length;
	int width;
};

