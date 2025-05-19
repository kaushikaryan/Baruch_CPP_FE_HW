/**
*
* Point.hpp
* Header file for the Point class that represents a point in 2D space
* with x and y coordinates.
*
* @author:  Kaushik Aryan R
* @date:    17-05-2025
* @version: 1.5
*
**/

#ifndef POINT_H
#define POINT_H

#include<iostream> // Required for std::string

/*
*
* Point class
*
* Class that represents a point in 2D space
* with x and y coordinates.
*
*/
class Point
{
private:
	double m_x; // X coordinate of the point
	double m_y; // Y coordinate of the point

public:
	// Constructors and Destructor
	Point();                            // Default constructor
	Point(const Point& point);          // Default constructor
	Point(double xVal, double yVal);    // Constructor that accepts X and Y coordinates
	~Point();                           // Destructor

	// Getter functions
	double X() const;  // Get the X coordinate
	double Y() const;  // Get the Y coordinate

	// Setter functions
	void X(const double& xval); // Set the X coordinate
	void Y(const double& yval); // Set the X coordinate

	// String representation
	std::string ToString() const; // Create a string representation of the point

	// Distance functions
	double Distance() const;    // Get the distance of the point from origin
	double Distance(const Point& p) const;   // Get the distance of the point from another point p
};

#endif
