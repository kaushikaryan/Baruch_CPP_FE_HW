/**
*
* Array.cpp
*
* Implementation file for the Array class that represents an
* array of the Point class, that represents
* a point in 2D space with x and y coordinates.
*
* @author:  Kaushik Aryan R
* @date:    24-05-2025
* @version: 1.0
*
**/

#include "Point.hpp"	// Header file for Point class
#include "Array.hpp"	// Header file for Array class


// Default constructor
Array::Array() : m_data(new Point[10]), m_size(10) {}

// Constructor that accepts size as argument
Array::Array(int size) : m_data(new Point[size]), m_size(size) {}

// Copy constructor
Array::Array(const Array& source)
{
	m_data = new Point[source.m_size];
	m_size = source.m_size;

	// Copying data one element at a time
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = source[i];
	}
}

// Destructor
Array::~Array()
{
	delete[] m_data;
}

// Get element of array at index
Point& Array::GetElement(int index) const
{
	// If index out of bounds, return the first element
	if (index < 0 || index >= m_size)
	{
		throw - 1;
	}

	// Return element at index
	return m_data[index];
}

// Set element of array at index
void Array::SetElement(int index, const Point& p)
{
	// Set the element only if index is not out of bounds
	if (index < 0 || index >= m_size)
	{
		throw - 1;
	}

	// Set element at index
	m_data[index] = p;
}

// Return size of the array
int Array::Size() const
{
	return m_size;
}

// Assignment operator
Array& Array::operator=(Array& source)
{
	// Check if source is same as current Array object
	if (this == &source)
	{
		return *this;
	}

	// Deleting old data
	delete[] m_data;

	// Set member data
	m_data = new Point[source.m_size];
	m_size = source.m_size;

	// Copying data one element at a time
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = source[i];
	}

	return *this;
}

// Square brackets operator
Point& Array::operator[](int index)
{
	// If index out of bounds, return the first element
	if (index < 0 || index >= m_size)
	{
		throw - 1;
	}

	// Return elemet at index
	return m_data[index];
}

/*
*
* Const version of the square brackets operator.
*
* This allows us to use the [] operator on Array objects declared as const,
* and also grants users to read only access to contents of the const Array.
*
*/
const Point& Array::operator[](int index) const
{
	// If index out of bounds, return the first element
	if (index < 0 || index >= m_size)
	{
		return m_data[0];
	}

	// Return elemet at index
	return m_data[index];
}

