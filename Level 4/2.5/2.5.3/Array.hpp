/**
*
* Array.hpp
* Header file for Array of the Point class that represents 
* a point in 2D space with x and y coordinates.
*
* @author:  Kaushik Aryan R
* @date:    24-05-2025
* @version: 1.0
*
**/

#ifndef ARRAY_H
#define ARRAY_H

#include "Point.hpp" // Header file for Point class

/*
*
* Array class
*
* Class that represents an array of the Point class
*
*/
class Array
{
private:
	Point* m_data;
	int m_size;

public:
	Array();					// Default constructor
	Array(int size);			// Constructor that accepts size as argument
	Array(const Array& array);	// Copy constructor
	~Array();					// Destructor

	// Getter
	Point& GetElement(int index) const;	// Getter for element if the array at index

	// Setter
	void SetElement(int index, const Point& p);	// Setter for element if the array at index

	// Functions
	int Size() const;	// Returns the size of the array

	// Operator overloading
	Array& operator= (Array& source);			// Assignment operator
	Point& operator[] (int index);				// Square bracket operator
	const Point& operator[] (int index) const;	// Const Square bracket operator

};

#endif