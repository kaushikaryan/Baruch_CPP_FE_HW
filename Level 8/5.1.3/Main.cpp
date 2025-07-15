/**
*
* Main.cpp
* C++ program to test Variants
*
* @author:  Kaushik Aryan R
* @date:    05-07-2025
* @version: 1.0
*
**/

#include <boost/variant.hpp>
#include <iostream>
#include "Point.hpp"
#include "Line.hpp"
#include "Circle.hpp"
#include "Visitor.hpp"

// Typedef for a shared pointer to shape
typedef boost::variant<Circle, Line, Point> ShapeType;

ShapeType getShape()
{
	// Print the options
	std::cout << "Enter the number to select the shape" << std::endl;
	std::cout << "1. Circle\n2. Line\n3. Point" << std::endl;

	ShapeType shape;
	int choice = 0;

	// Get and validate the choice from the user
	while (choice < 1 || choice > 3)
	{
		std::cin >> choice;

		switch (choice)
		{
		case 1:
			shape = Circle();
			break;

		case 2:
			shape = Line();
			break;

		case 3:
			shape = Point();
			break;

		default:
			std::cout << "Invalid choice, please enter a number from the provided options and try again" << std::endl;
			break;
		}
	}

	// Return chosen shape
	return shape;
}

/*
*
* main function - entry point of the program
*
* @return 0 on successful execution
*
*/
int main()
{

	// Get shape chosen by user
	ShapeType shape = getShape();

	// Print shape chosen by user
	std::cout << shape << std::endl;

	// Assign the variant to a line
	try
	{
		Line line = boost::get<Line>(shape);
	}
	catch (boost::bad_get& exception)
	{
		// Catch and print exception
		std::cout << "Exception: " << exception.what() << std::endl;
	}

	// Move the shapes
	Visitor visitor(4, 6);
	boost::apply_visitor(visitor, shape);
	std::cout << shape << std::endl;

	// Return successful execution
	return 0;
}