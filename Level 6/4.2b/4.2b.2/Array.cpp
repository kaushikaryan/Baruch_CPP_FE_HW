/**
*
* Array.cpp
* Implementation file for the Array class
*
* @author:  Kaushik Aryan R
* @date:    10-06-2025
* @version: 1.0
*
**/

#ifndef ARRAY_CPP
#define ARRAY_CPP

#include "Array.hpp"
#include "OutOfBoundsException.hpp"
#include <iostream>
#include <sstream>

template <typename T>
int Array<T>::m_default_size = 10;

// Default constructor
template <typename T>
Array<T>::Array() : m_data(new T[m_default_size]), m_size(m_default_size) {}

// Constructor that accepts size as argument
template <typename T>
Array<T>::Array(int size) : m_data(new T[size]), m_size(size) {}

// Copy constructor
template <typename T>
Array<T>::Array(const Array<T>& source)
{
	m_data = new T[source.m_size];
	m_size = source.m_size;

	// Copying data one element at a time
	for (int i = 0; i < m_size; i++)
	{
		m_data[i] = source[i];
	}
}

// Destructor
template <typename T>
Array<T>::~Array()
{
	delete[] m_data;
}

// Get element of array at index
template <typename T>
T& Array<T>::GetElement(int index) const
{
	// If index out of bounds, throw OutOfBoundsException
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	}

	// Return element at index
	return m_data[index];
}

// Getter for default size of array 
template<typename T>
int Array<T>::DefaultSize()
{
	return m_default_size;
}

// Set element of array at index
template <typename T>
void Array<T>::SetElement(int index, const T& t)
{
	// Set the element only if index is not out of bounds
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	}

	// Set element at index
	m_data[index] = t;
}

// Setter for default size of array
template<typename T>
void Array<T>::DefaultSize(int size)
{
	m_default_size = size;
}

// Return size of the array
template <typename T>
int Array<T>::Size() const
{
	return m_size;
}

// Assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& source)
{
	// Check if source is not same as current Array object
	if (this != &source)
	{
		// Deleting old data
		delete[] m_data;

		// Set member data
		m_data = new T[source.m_size];
		m_size = source.m_size;

		// Copying data one element at a time
		for (int i = 0; i < m_size; i++)
		{
			m_data[i] = source[i];
		}
	}

	return *this;
}

// Square brackets operator
template <typename T>
T& Array<T>::operator[](int index)
{
	// If index out of bounds, throw OutOfBoundsException
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
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
template <typename T>
const T& Array<T>::operator[](int index) const
{
	// If index out of bounds, return the first element
	if (index < 0 || index >= m_size)
	{
		throw OutOfBoundsException(index);
	}

	// Return element at index
	return m_data[index];
}

// String representation of the array
template<typename T>
std::string Array<T>::ToString() const
{
	std::stringstream stream;

	// Formatting the string
	stream << "[";
	for (int i = 0; i < m_size - 1; i++)
		stream << m_data[i] << ", ";
	stream << m_data[m_size - 1] << "]" << std::endl;

	return stream.str();
}

#endif	// ARRAY_CPP

