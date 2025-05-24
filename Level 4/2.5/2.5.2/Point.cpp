/**
*
* Point.cpp
*
* Implementation file for the Point class that represents a 2D point
* with x and y coordinates
*
* @author:  Kaushik Aryan R
* @date:    24-05-2025
* @version: 1.0
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

// Constructor that accepts a single double value
Point::Point(double val) : m_x(val), m_y(val)
{
	// Intentionally blank
}

// Destructor
Point::~Point()
{
	// Intentionally blank
}

// Get the x-coordinate
double Point::X() const
{
	return m_x; // Return the x-coordinate
}

// Get the y-coordinate
double Point::Y() const
{
	return m_y; // Return the y-coordinate
}

// Set the x-coordinate
void Point::X(const double& xVal)
{
	m_x = xVal; // Set the x-coordinate to the provided value
}

// Set the y-coordinate
void Point::Y(const double& yVal)
{
	m_y = yVal; // Set the y-coordinate to the provided value
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

// Negate the coordinates
Point Point::operator-() const
{
	return Point(-m_x, -m_y);
}

// Scale the coordinates
Point Point::operator*(double factor) const
{
	// Multiply each coordinate by the factor
	return Point(factor * m_x, factor * -m_y);
}

// Add coordinates
Point Point::operator+(const Point& p) const
{
	// Add x and y coordinates of this object to 
	// x and y coordinates of Point p respectively
	return Point(p.m_x + m_x, p.m_y + m_y);
}

// Equally compare operator
bool Point::operator==(const Point& p) const
{
	// Check if coordinates of current Point object are equal to those of Point p
	return (m_x == p.m_x && m_y == p.m_y) ? true : false;
}

// Assignment operator
Point& Point::operator=(const Point& source)
{
	// Check if source object is same as current object
	if (this == &source)
	{
		// Skip copy and directly return this object
		return *this;
	}

	// Copy values from source object into current object
	m_x = source.m_x;
	m_y = source.m_y;

	return *this;
}

// Scale the coordinates & assign
Point& Point::operator*=(double factor)
{
	// Scale each coordinate by a factor
	m_x = factor * m_x;
	m_y = factor * m_y;

	return *this;
}

// Send to ostream
ostream& operator<<(ostream& os, const Point& p)
{
	// Accessing member data
	os << "Point(" << p.m_x << ", " << p.m_y << ")";
	return os;
}
