/**
*
* Shape.hpp
* Header file for the Shape base class.
*
* @author:  Kaushik Aryan R
* @date:    01-06-2025
* @version: 1.0
*
**/

#ifndef SHAPE_H
#define SHAPE_H

#include<iostream> // Required for std::string

/*
*
* Shape class
*
* Base class for Shapes
*
*/
class Shape
{
private:
	int id;	// id number of the shape

public:
	// Constructors and Destructor
	Shape();                            // Default constructor
	Shape(const Shape& shape);          // Copy constructor
	virtual ~Shape();                   // Destructor

	// Getter functions
	double ID() const;	// Get the id of the shape

	// String representation
	std::string ToString() const; // Create a string representation of the shape

	// Operator overloading
	Shape& operator = (const Shape& source); // Assignment operator
};

#endif