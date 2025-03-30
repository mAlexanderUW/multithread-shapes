#include "Rectangle.h"


Rectangle::Rectangle(int l, int w)
{
	length = l;
	width = w;
}

float Rectangle::getArea()
{
	area = length * width;

	return area;
}

float Rectangle::getVolume()
{
	volume = length * width * z;

	return volume;
}

std::string Rectangle::getShape()
{
	return "Rectangle";
}

void Rectangle::Print()
{
	std::cout << "Shape: " << getShape() << "\n";
	std::cout << "Length = " << length << " Width = " << width << "\n";
	std::cout << "Area = " << getArea() << "\n";
	std::cout << "Height = " << z << "\n";
	std::cout << "Volume = " << getVolume() << "\n\n";
}
