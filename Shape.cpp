#include "Shape.h"

Shape::Shape()
{
}

Shape::~Shape()
{
}

float Shape::getArea()
{
	return area;
}

void Shape::setZ(int height)
{
	z = height;
}


float Shape::getVolume()
{
	return volume;
}

std::string Shape::getShape()
{
	return "Generic Shape";
}

void Shape::Print()
{
	std::cout << getShape() << "\n\n";
}

