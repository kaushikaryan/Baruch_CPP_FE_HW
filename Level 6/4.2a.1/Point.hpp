/**
*
* Point.hpp
* 
* Header file for the Point class that represents a point in 2D space
* with x and y coordinates.
*
* @author:  Kaushik Aryan R
* @date:    01-06-2025
* @version: 1.0
*
**/

#ifndef POINT_H
#define POINT_H

#include "Shape.hpp"
#include <iostream>

/*
*
* Point class
*
* Class that represents a point in 2D space
* with x and y coordinates.
*
*/
class Point : public Shape
{
private:
	double m_x; // X coordinate of the point
	double m_y; // Y coordinate of the point

public:
	// Constructors and Destructor
	Point();                            // Default constructor
	Point(const Point& point);          // Copy constructor
	Point(double xVal, double yVal);    // Constructor that accepts X and Y coordinates
	explicit Point(double val);			// Constructor that accepts a single double value
	virtual ~Point();					// Destructor

	// Getter functions
	double X() const;  // Get the X coordinate
	double Y() const;  // Get the Y coordinate

	// Setter functions
	void X(const double& xval); // Set the X coordinate
	void Y(const double& yval); // Set the Y coordinate

	// String representation
	std::string ToString() const; // Create a string representation of the point

	// Distance functions
	double Distance() const;    // Get the distance of the point from origin
	double Distance(const Point& p) const;   // Get the distance of the point from another point p

	// Operator overloading
	Point operator - () const;               // Negate the coordinates
	Point operator * (double factor) const;  // Scale the coordinates 
	Point operator + (const Point& p) const; // Add coordinates 
	bool operator == (const Point& p) const; // Equally compare operator
	Point& operator = (const Point& source); // Assignment operator
	Point& operator *= (double factor);      // Scale the coordinates & assign

	// Friend function
	friend std::ostream& operator << (std::ostream& os, const Point& p); // Send to ostream

	// Other member functions
	void Draw() const;
};

#endif