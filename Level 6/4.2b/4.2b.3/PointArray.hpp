/**
*
* PointArray.hpp
* Header file for the PointArray class
*
* @author:  Kaushik Aryan R
* @date:    12-06-2025
* @version: 1.0
*
**/

#ifndef POINT_ARRAY_H
#define POINT_ARRAY_H

#include "Array.hpp"
#include "Point.hpp"

class PointArray : public Array<Point>
{
public:
	PointArray();							// Default constructor
	PointArray(int size);					// Constructor that takes size as input
	PointArray(const PointArray& source);	// Copy constructor
	~PointArray();							// Destructor

	PointArray& operator= (const PointArray& source);	// Assignment operator

	double Length() const;	// Find total length between points in array
};

#endif	// POINT_ARRAY_H