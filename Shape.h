#pragma once
#include <typeinfo>
#include <iostream>
#include <string>

class Shape
{
public:
	Shape();
	virtual ~Shape();
	virtual float getArea();
	virtual float getVolume();
	virtual std::string getShape();
	virtual void Print();
	void setZ(int);

protected:
	int z;
	float area;
	float volume;
};

