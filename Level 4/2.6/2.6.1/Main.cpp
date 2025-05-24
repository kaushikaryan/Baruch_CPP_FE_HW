/**
*
* Main.cpp
*
* C++ program to test namespaces.
* The program, initializes Point, Line, Circle and Array objects
* while using different declarations of namespaces.
*
* @author:  Kaushik Aryan R
* @date:    24-05-2025
* @version: 1.0
*
**/

#include "Point.hpp"	// Header file for Point class
#include "Line.hpp"		// Header file for Line class
#include "Circle.hpp"	// Header file for Circle class
#include "Array.hpp"	// Heafer file for Array class
#include <iostream>

// Using standard namespace to simplify code
using namespace std;

/*
*
* main function - entry point of the program
*
* @return 0 on successful execution
*
*/
int main()
{
	// Using full namespace for Point class
	KAUSHIK_ARYAN_R::CAD::Point p1(3, 4);
	KAUSHIK_ARYAN_R::CAD::Point p2(6, 8);
	cout << p1 << endl;

	// Using declaration for a single class
	using KAUSHIK_ARYAN_R::CAD::Line;
	{
		cout << Line(p1, p2) << endl;
	}

	// Creating alias and using it for the Circle class
	namespace KCAD = KAUSHIK_ARYAN_R::CAD;
	using KCAD::Circle;
	{
		Circle c1(KCAD::Point(4, -8), 10);
		cout << c1 << endl; 
	}

	// Using declaration for a complete namesppace
	using namespace KAUSHIK_ARYAN_R::Containers;
	{
		Array arrOne(1);
		arrOne.SetElement(0, KAUSHIK_ARYAN_R::CAD::Point(5, 12));
		cout << "arrOne.GetElement(0) = " << arrOne.GetElement(0) << endl;
	}

	// Return successful execution
	return 0;
}