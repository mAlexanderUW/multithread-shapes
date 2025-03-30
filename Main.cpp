#include "Main.h"

int main() 
{
	//RNG thread for creating random data for the shapes
	std::thread randomThread(RandomNumbers);

	//Creation of Objects
	std::vector <Shape*> Rectangles;
	std::vector <Shape*> Triangles;
	std::vector <Shape*> Circles;
	std::vector <Shape*> Shapes;
	std::vector <Shape*> ShapesTwo;

	// thread(Function, vector of shapes, qty of shapes)
	std::thread genRecThread(CreateRectangles, std::ref(Rectangles), 10); 
	std::thread genTriThread(CreateTriangles, std::ref(Triangles), 10);
	std::thread genCirThread(CreateCircles, std::ref(Circles), 10);
	std::thread genShpThread(CreateShapes, std::ref(Shapes), 10);
	std::thread genShpThread2(CreateShapes, std::ref(ShapesTwo), 15);

	genRecThread.join();
	genTriThread.join();
	genCirThread.join();
	genShpThread.join();
	genShpThread2.join();

	//Changing shapes to 3D adding a Z value
	std::thread changeRecData(ChangeShapesTo3D, std::ref(Rectangles));
	std::thread changeTriData(ChangeShapesTo3D, std::ref(Triangles));
	std::thread changeCirData(ChangeShapesTo3D, std::ref(Circles));
	std::thread changeShpData(ChangeShapesTo3D, std::ref(Shapes));
	std::thread changeShpData2(ChangeShapesTo3D, std::ref(ShapesTwo));
	
	changeRecData.join();
	changeTriData.join();
	changeCirData.join();
	changeShpData.join();
	changeShpData2.join();

	//Done with using RNG
	Finished();
	randomThread.join();
	
	//Display shape that were created
	std::thread displayRecData(PrintShapes, std::ref(Rectangles));
	std::thread displayTriData(PrintShapes, std::ref(Triangles));
	std::thread displayCirData(PrintShapes, std::ref(Circles));
	std::thread displayShpData(PrintShapes, std::ref(Shapes));
	std::thread displayShpData2(PrintShapes, std::ref(ShapesTwo));

	displayRecData.join();
	displayTriData.join();
	displayCirData.join();
	displayShpData.join();
	displayShpData2.join();
	
	std::thread tallyRecData(TallyTotals, std::ref(Rectangles));
	std::thread tallyTriData(TallyTotals, std::ref(Triangles));
	std::thread tallyCirData(TallyTotals, std::ref(Circles));
	std::thread tallyShpData(TallyTotals, std::ref(Shapes));
	std::thread tallyShpData2(TallyTotals, std::ref(ShapesTwo));

	tallyRecData.join();
	tallyTriData.join();
	tallyCirData.join();
	tallyShpData.join();
	tallyShpData2.join();

	DisplayTotals();
}

//RNG
void RandomNumbers()
{
	srand(time(0)); //seed to make rand somewhat actually random

	while (needValue)
	{
		sendLock.acquire();
		randomNumber = rand() % 25 + 1; //1 through 25
		recieveLock.release();
	}
}
//Event to allow the RNG
void Finished()
{
	needValue = false;
	sendLock.release();
}

//functions create shapes (Rectangle,Triangle,Circle,Combo of all three)
void CreateRectangles(std::vector <Shape*>& rec, int qty)
{
	for (int i = 0; i < qty; i++)
	{
		recieveLock.acquire();
		length = randomNumber;
		sendLock.release();

		recieveLock.acquire();
		width = randomNumber;
		sendLock.release();

		rec.push_back(new Rectangle(length, width));
	}
}

void CreateTriangles(std::vector <Shape*>& tri, int qty)
{
	for (int i = 0; i < qty; i++)
	{
		recieveLock.acquire();
		length = randomNumber;
		sendLock.release();

		recieveLock.acquire();
		width = randomNumber;
		sendLock.release();

		tri.push_back(new Triangle(length, width));
	}
}
void CreateCircles(std::vector <Shape*>& cir, int qty)
{
	for (int i = 0; i < qty; i++)
	{
		recieveLock.acquire();
		radius = randomNumber;
		sendLock.release();

		cir.push_back(new Circle(radius));
	}
}

void CreateShapes(std::vector <Shape*>& shp, int qty)
{
	//used with the rng%3 to randomize the shapes made
	int idx;

	for (int i = 0; i < qty; i++)
	{
		recieveLock.acquire();
		idx = randomNumber % 3; //random number mod 3
		sendLock.release();

		switch (idx)
		{
		case 0:
			recieveLock.acquire();
			length = randomNumber;
			sendLock.release();

			recieveLock.acquire();
			width = randomNumber;
			sendLock.release();

			shp.push_back(new Rectangle(length, width));
			break;

		case 1:
			recieveLock.acquire();
			length = randomNumber;
			sendLock.release();

			recieveLock.acquire();
			width = randomNumber;
			sendLock.release();

			shp.push_back(new Triangle(length, width));
			break;

		case 2:
			recieveLock.acquire();
			radius = randomNumber;
			sendLock.release();

			shp.push_back(new Circle(radius));
			break;
		}
	}
}

//Alters object adding a z value
void ChangeShapesTo3D(std::vector <Shape*>& shape)
{
	for (auto& shape : shape)
	{
		recieveLock.acquire();
		height = randomNumber;
		shape->setZ(height);
		sendLock.release();
	}
}

//Prints Shape type, dimensions, area , height, volume
void PrintShapes(std::vector <Shape*>& shape)
{
	for (auto shape : shape)
	{
		displayLock.acquire();
		shape->Print();
		displayLock.release();
	}
}
//Tally number of each type of shape and overall totals for area and volume
void TallyTotals(std::vector <Shape*>& shape)
{
	for (auto shape : shape)
	{
		displayLock.acquire();
		if (dynamic_cast<Rectangle*>(shape))
		{
			totalRectangles += 1;
			totalArea += shape->getArea();
			totalVolume += shape->getVolume();
		}
		else if (dynamic_cast<Triangle*>(shape))
		{
			totalTriangles += 1;
			totalArea += shape->getArea();
			totalVolume += shape->getVolume();
		}
		else if (dynamic_cast<Circle*>(shape))
		{
			totalCircles += 1;
			totalArea += shape->getArea();
			totalVolume += shape->getVolume();
		}
		displayLock.release();
	}
}
void DisplayTotals()
{
	std::cout << "Number of Rectangles: " << totalRectangles << "\n";
	std::cout << "Number of Triangles: " << totalTriangles << "\n";
	std::cout << "Number of Circles: " << totalCircles << "\n";
	std::cout << "Total Area: " << totalArea << "\n";
	std::cout << "Total Volume: " << totalVolume << "\n";
}

