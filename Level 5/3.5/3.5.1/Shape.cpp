/**
*
* Shape.hpp
*
* Implementation file for the Shape base class.
*
* @author:  Kaushik Aryan R
* @date:    01-06-2025
* @version: 1.0
*
**/

#include "Shape.hpp"
#include "stdlib.h"
#include <sstream>

// Default Constructor
Shape::Shape() : id(rand()) {}

// Copy Constructor
Shape::Shape(const Shape& shape) : id(shape.id) {}

// Destructor
Shape::~Shape() {}

// Getter
double Shape::ID() const
{
	return id;
}

// String representation
std::string Shape::ToString() const
{
	// Create a stringstream to build the output string
	std::stringstream stream;

	// Format the id as ID: id
	stream << "ID: " << id;

	// Return the resulting string
	return stream.str();
}

// Assignment operator
Shape& Shape::operator=(const Shape& source)
{
	if (this == &source)
		return *this;

	id = source.id;

	return *this;

}
