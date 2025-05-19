/**
* 
* Point.cpp
* 
* Implementation file for the Point class that represents a 2D point
* with x and y coordinates
* 
* @author:	Kaushik Aryan R
* @date:	12-05-2025
* @version:	1.0
* 
**/

#include <iostream>
#include <sstream>
#include "Point.hpp" // Header file for Point class

// Using standard namespace to simplify code
using namespace std;

// Default constructor
Point::Point() : m_x(0), m_y(0)
{
	// Intentionally empty
}

// Destructor
Point::~Point()
{
	// Intentionally empty
}

// Get the x-coordinate
double Point::GetX()
{
	return m_x; // Return the x-coordinate
}

// Get the y-coordinate
double Point::GetY()
{
	return m_y; // Return the y-coordinate
}

// Set the x-coordinate
void Point::SetX(double& xVal)
{
	m_x = xVal; // Set the x-coordinate to the provided value
}


// Set the y-coordinate
void Point::SetY(double& yVal)
{
	m_y = yVal; // Set the y-coordinate to the provided value
}

/*
*
* ToString function implementation
*
* Creates a string representation of the Point.
*
* @return string representation of the Point
*
*/
string Point::ToString()
{
	// Create a stringstream to build the output string
	stringstream stream;

	// Format the point as Point(x, y)
	stream << "Point(" << m_x << ", " << m_y << ")";
	
	// Return the resulting string
	return stream.str();
}
