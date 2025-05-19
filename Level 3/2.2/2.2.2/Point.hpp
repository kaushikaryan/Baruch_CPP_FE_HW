/**
*
* Point.hpp
* Header file for the Point class that represents a point in 2D space
* with x and y coordinates.
*
* @author:	Kaushik Aryan R
* @date:	17-05-2025
* @version:	1.1
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
	Point();	// Default constructor
	~Point();	// Destructor

	// Getter functions
	double GetX();	// Get the X coordinate
	double GetY();	// Get the Y coordinate

	// Setter functions
	void SetX(double& xval); // Set the X coordinate
	void SetY(double& yval); // Set the Y coordinate

	// String representation
	std::string ToString();	// Create a string representation of the point

	// Distance functions
	double DistanceOrigin();	// Get the distance of the point from the origin
	double Distance(Point p);	// Get the distance of the point from another point p
};

#endif