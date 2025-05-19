/**
*
* Line.cpp
*
* Implementation file for the Line class that represents a line
* with start and end Points.
*
* @author:  Kaushik Aryan R
* @date:    17-05-2025
* @version: 1.0
*
**/

#include <iostream>
#include <sstream>
#include <cmath>
#include "Line.hpp" // Header file for Line class

// Using standard namespace to simplify code
using namespace std;

// Default constructor
Line::Line() : P1_(0, 0), P2_(0, 0)
{
	// Intentionally blank
}

// Constructor that accepts start and end points
Line::Line(const Point& p1, const Point& p2) : P1_(p1) , P2_(p2)
{
	// Intentionally blank
}

// Copy constructor
Line::Line(const Line& line) : P1_(line.P1_), P2_(line.P2_)
{
	// Intentionally blank
}

// Destructor
Line::~Line()
{
	// Intentionally blank
}

// Getter for start point P1
Point Line::P1() const
{
	return P1_;
}

// Getter for end point P2
Point Line::P2() const
{
	return P2_;
}

// Setter for start point P1
void Line::P1(const Point& p1)
{
	P1_ = p1;
}

// Setter for end point P2
void Line::P2(const Point& p2)
{
	P2_ = p2;
}

/*
*
* ToString function implementation
*
* Creates a string representation of the Line.
*
* @return str: string representation of the Line
*
*/
std::string Line::ToString() const
{
	// Create a stringstream to build the output string
	stringstream stream;

	// Format the line as Line: Point1(x1, y1), Point2(x2, y2)
	stream << "Line: " << P1_.ToString() << ", " << P2_.ToString() << endl;

	// Return the resulting string
	return stream.str();
}

/*
*
* Length function implementation
*
* Calculates the length of the line.
*
* @return length: the length of the line
*
*/
double Line::Length() const
{
	// Length of the line is the distance between the start and end points
	return P1_.Distance(P2_);
}