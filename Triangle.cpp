#include "Triangle.h"

Triangle::Triangle(int l, int w)
{
	length = l;
	width = w;
}

float Triangle::getArea()
{
	area = (length * width) / 2;

	return area;
}

float Triangle::getVolume()
{
	volume = (length * width * z) / 3;

	return volume;
}

std::string Triangle::getShape()
{
	return "Triangle";
}

void Triangle::Print()
{
	std::cout << "Shape: " << getShape() << "\n";
	std::cout << "Length = " << length << " Width = " << width << "\n";
	std::cout << "Area = " << getArea() << "\n";
	std::cout << "Height = " << z << "\n";
	std::cout << "Volume = " << getVolume() << "\n\n";
}


