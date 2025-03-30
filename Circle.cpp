#include "Circle.h"

Circle::Circle(int r)
{
	radius = r;
}

float Circle::getArea()
{
	area = PI * radius * radius;
	return area;
}

float Circle::getVolume()
{
	volume = PI * radius * radius * z;
	return volume;
}

std::string Circle::getShape()
{
	return "Circle";
}

void Circle::Print()
{
	std::cout << "Shape: " << getShape() << "\n";
	std::cout << "Radius = " << radius << "\n";
	std::cout << "Area = " << getArea() << "\n";
	std::cout << "Height = " << z << "\n";
	std::cout << "Volume = " << getVolume() << "\n\n";
}
