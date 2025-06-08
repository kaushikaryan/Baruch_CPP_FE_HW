/**
*
* Circle.cpp
*
* Implementation file for the Circle class that represents a circle
* with radius and center Point.
*
* @author:  Kaushik Aryan R
* @date:    23-05-2025
* @version: 1.0
*
**/

#define _USE_MATH_DEFINES	// Letting the compiler know that we wish to use the Math defines

#include <iostream>
#include <sstream>
#include <cmath>
#include "Circle.hpp"	// Header file for Circle class
#include "Point.hpp"	// Header file for Point class

// Using standard namespace to simplify code
using namespace std;

// Default constructor
Circle::Circle() : Shape(), m_radius(0), m_centre(0, 0) {}

// Copy constructor 
Circle::Circle(Circle& circle) : Shape(circle), m_centre(circle.m_centre), m_radius(circle.m_radius) {}

// Constructor that accepts center point and radius
Circle::Circle(const Point& point, const double& radius) : Shape(), m_centre(point), m_radius(radius) {}

// Destructor
Circle::~Circle() {}

// Get the center Point
Point Circle::CentrePoint() const
{
	return m_centre;
}

// Get the radius
double Circle::Radius() const
{
	return m_radius;
}

// Get the diameter
double Circle::Diameter() const
{
	// Diameter is twice the radius
	return 2 * m_radius;
}

/*
*
* Area function implementation
*
* Calculates the area of the Circle.
*
* @return area: the area of the circle calculated as pi*r^2
*
*/
double Circle::Area() const
{
	// Area of circle = pi * r^2
	return M_PI * pow(m_radius, 2);
}

/*
*
* Circumference function implementation
*
* Calculates the circumference of the Circle.
*
* @return circumference: the circumference of the circle calculated as 2*pi*r
*
*/
double Circle::Circumference() const
{
	// Circumference = 2 * pi * r
	return 2 * M_PI * m_radius;
}

// Set the center point
void Circle::CentrePoint(const Point& point)
{
	m_centre = point;
}

// Set the radius
void Circle::Radius(const double& radius)
{
	m_radius = radius;
}

/*
*
* ToString function implementation
*
* Creates a string representation of the Circle.
*
* @return str: string representation of the Circle
*
*/
std::string Circle::ToString() const
{
	// Create a stringstream to build the output string
	stringstream stream;

	// Format the Circle as Circle: Point(x, y), Radius:
	stream << "Circle: " << m_centre.ToString() << ", Radius: " << m_radius;

	// Return the resulting string
	return stream.str();
}

// Assignment operator
Circle& Circle::operator=(const Circle& source)
{
	// Check if source object is not same as current object
	if (this != &source)
	{
		// Call assignment operator of the Shape class
		Shape::operator=(source);

		// Copy values from source object into current object
		m_centre = source.m_centre;
		m_radius = source.m_radius;
	}

	return *this;
}

// Send to ostream
ostream& operator<<(ostream& os, const Circle& c)
{
	os << c.ToString();
	return os;
}