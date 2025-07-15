/**
*
* Main.cpp
* C++ program to test Shared Pointers
*
* @author:  Kaushik Aryan R
* @date:    25-06-2025
* @version: 1.0
*
**/

#include <boost/shared_ptr.hpp>
#include <iostream>
#include "Array.hpp"
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"

/*
*
* main function - entry point of the program
*
* @return 0 on successful execution
*
*/
int main()
{
	// Typedef for a shared pointer to shape
	typedef boost::shared_ptr<Shape> ShapePtr;
	
	// Typedef for an array with shapes stored as shared pointers
	typedef Array<ShapePtr> ShapeArray;

	// Creating shared pointers of different shapes
	ShapePtr point(new Point(1, 2));
	ShapePtr line(new Line(Point(3, 4), Point(5, 6)));
	ShapePtr circle(new Circle(Point(7, 8), 9));

	{
		ShapeArray shapeArray(3);

		// Adding shared pointers to array
		shapeArray[0] = point;	// point reference count becomes 2
		shapeArray[1] = line;	// line reference count becomes 2
		shapeArray[2] = circle;	// circle reference count becomes 2

		// Print string representation of shapes
		for (int i = 0; i < shapeArray.Size(); i++)
			std::cout << shapeArray[i]->ToString() << std::endl;
		
		// Print reference counts
		std::cout << "\nAfter adding to array:" << std::endl;
		std::cout << "point:" << point.use_count() << std::endl;
		std::cout << "line:" << line.use_count() << std::endl;
		std::cout << "circle:" << circle.use_count() << std::endl;
	}

	// Verify reference count goes back down to 1
	std::cout << "\nOutside inner scope, array destroyed:" << std::endl;
	std::cout << "point:" << point.use_count() << std::endl;
	std::cout << "line:" << line.use_count() << std::endl;
	std::cout << "circle:" << circle.use_count() << std::endl;
	
	// Return successful execution
	return 0;
}