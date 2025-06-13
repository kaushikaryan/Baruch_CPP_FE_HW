/**
*
* PointArray.cpp
* Implementation file for the PointArray class
*
* @author:  Kaushik Aryan R
* @date:    12-06-2025
* @version: 1.0
*
**/

#ifndef POINT_ARRAY_CPP
#define POINT_ARRAY_CPP

#include "PointArray.hpp"

// Default constructor
PointArray::PointArray() : Array<Point>() {}

// Constructor that takes size as input
PointArray::PointArray(int size) : Array<Point>(size) {}

// Copy constructor
PointArray::PointArray(const PointArray& source) : Array<Point>(source) {}

// Destructor
PointArray::~PointArray() {}

// Assignment operator
PointArray& PointArray::operator=(const PointArray& source)
{
	if (this != &source)
		// Call base class assignment operator
		Array<Point>::operator=(source);
	
	return *this;
}

// Function to compute total length between adjacent Point elements of PointArray
double PointArray::Length() const
{
	double length = 0.0;

	// Computing distance between adjacent elements of PointArray
	for (int i = 1; i < Size(); i++)
		length += (*this)[i - 1].Distance((*this)[i]);

	return length;
}

#endif	// POINT_ARRAY_CPP