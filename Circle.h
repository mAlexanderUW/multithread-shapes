#pragma once
#include "Shape.h"


class Circle : public Shape
{
public:
	Circle(int);
	float getArea() override;
	float getVolume() override;
	std::string getShape() override;
	void Print() override;

private:
	int radius;
	float PI = 3.14;
};

