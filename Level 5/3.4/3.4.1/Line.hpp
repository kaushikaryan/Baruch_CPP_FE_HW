/**
*
* Line.hpp
*
* Header file for the Line class that represents a line
* with start and end points.
*
* @author:  Kaushik Aryan R
* @date:    01-06-2025
* @version: 1.0
*
**/

#ifndef LINE_H
#define LINE_H

#include "Point.hpp"

/*
*
* Line class
*
* Class that represents a line
* with start and end Points.
*
*/
class Line
{
private:
	Point P1_; // Start point of the line
	Point P2_; // End point of the line

public:
	// Constructors and destructor
	Line();										// Default constructor
	Line(const Point& P1_, const Point& P2_);	// Constructor that accepts start and end points
	Line(const Line& line);						// Copy constructor
	~Line();									// Destructor

	// Getter functions
	const Point& P1() const;	// Getter for start point P1
	const Point& P2() const;	// Getter for end point P2

	// Setter functions
	void P1(const Point& P1_);	// Setter for start point P1
	void P2(const Point& P2_);	// Setter for end point P2

	// String representation
	std::string ToString() const;	// Create a string representation of the Line

	// Length functions
	double Length() const;	// Calculate the length of the line

	// Operator overloading
	Line& operator = (const Line& source); // Assignment operator

	// Friend function
	friend std::ostream& operator<<(std::ostream& os, const Line& l); // Send to ostream
};

#endif