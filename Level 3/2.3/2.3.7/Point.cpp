/**
*
* Point.cpp
*
* Implementation file for the Point class that represents a 2D point
* with x and y coordinates
*
* @author:  Kaushik Aryan R
* @date:    17-05-2025
* @version: 1.7
*
**/

#include <iostream>
#include <sstream>
#include <cmath>
#include "Point.hpp" // Header file for Point class

// Using standard namespace to simplify code
using namespace std;

// Default constructor
Point::Point() : m_x(0), m_y(0)
{
	// Intentionally blank
}

// Copy constructor
Point::Point(const Point& point) : m_x(point.m_x), m_y(point.m_y)
{
	// Intentionally blank
}

// Constructor that accepts X and Y coordinates
Point::Point(const double xVal, const double yVal) : m_x(xVal), m_y(yVal)
{
	// Intentionally blank
}

// Destructor
Point::~Point()
{
	// Intentionally blank
}

/*
*
* ToString function implementation
*
* Creates a string representation of the Point.
*
* @return str: string representation of the Point
*
*/
string Point::ToString() const
{
	// Create a stringstream to build the output string
	stringstream stream;

	// Format the point as Point(x, y)
	stream << "Point(" << m_x << ", " << m_y << ")";

	// Return the resulting string
	return stream.str();
}

/*
*
* DistanceOrigin function implementation
*
* Calculates the distance between this point and the origin (0,0).
*
* @return distance: the Euclidean distance from this point to the origin
*
*/
double Point::Distance() const
{
	// Use Pythogoras theorem to find distance from origin (l = sqrt(x^2 + y^2))
	return sqrt(pow(m_x, 2) + pow(m_y, 2));
}

/*
*
* Distance function implementation
*
* Calculates the distance between this point and another Point object.
*
* @param p: the other Point object to calculate distance to
* @return distance: the Euclidean distance between this point and the parameter point
*
*/
double Point::Distance(const Point& p) const
{
	// Use Distance equation to find distance from another point (l = sqrt((x2-x1)^2 + (y2-y1)^2))
	return sqrt(pow(m_x - p.m_x, 2) + pow(m_y - p.m_y, 2));
}
