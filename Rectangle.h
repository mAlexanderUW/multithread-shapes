#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle(int, int);
	float getArea() override;
	float getVolume() override;
	std::string getShape() override;
	void Print() override;

private:
	int length;
	int width;
};

