/**
*
* Circle.hpp
*
* Header file for the Circle class that represents a circle
* with radius and center Point.
*
* @author:  Kaushik Aryan R
* @date:    23-05-2025
* @version: 1.0
*
**/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.hpp"
#include "Point.hpp"
#include <iostream>

/*
*
* Circle class
*
* Class that represents a circle
* with radius and center Point.
*
*/
class Circle : public Shape
{
private:
	Point m_centre;		// Center Point of the Circle
	double m_radius;	// Radius of the Circle

public:
	// Constructors and destructor
	Circle();											// Default constructor
	Circle(const Circle& circle);						// Copy constructor
	Circle(const Point& point, const double& radius);	// Constructor that takes center Point and radius as input
	virtual ~Circle();											// Destructor

	// Getter functions
	Point CentrePoint() const;		// Getter for center Point of circle
	double Radius() const;			// Getter for radius of Circle
	double Diameter() const;		// Getter for diameter of Circle
	double Area() const;			// Getter for area of Circle
	double Circumference() const;	// Getter for circumference of Circle

	// Setter functions
	void CentrePoint(const Point& point);	// Setter for center Point of Circle
	void Radius(const double& radius);		// Setter for radius of Circle

	// String representation
	std::string ToString() const;	// Create a string representation of the Circle

	// Operator overloading
	Circle& operator = (const Circle& source); // Assignment operator

	// Other member functions
	void Draw() const;
};

// Global operator overloading
std::ostream& operator<<(std::ostream& os, const Circle& c); // Send to ostream

#endif