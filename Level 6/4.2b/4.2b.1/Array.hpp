/**
*
* Array.hpp
* Header file for Array class
* 
* @author:  Kaushik Aryan R
* @date:    10-06-2025
* @version: 1.0
*
**/

#ifndef ARRAY_H
#define ARRAY_H

/*
*
* Array class
*
* Class that represents an array
*
*/
template <typename T>
class Array
{
private:
	T* m_data;						// Pointer to dynamically allocated array data 
	int m_size;						// Size of the array
	static int m_default_size;		// Static member for the default size

public:
	Array();						// Default constructor
	Array(int size);				// Constructor that accepts size as argument
	Array(const Array<T>& array);	// Copy constructor
	~Array();						// Destructor

	// Getter
	T& GetElement(int index) const;	// Getter for element if the array at index
	static int DefaultSize();		// Getter for default size of array 

	// Setter
	void SetElement(int index, const T& t);	// Setter for element if the array at index
	static void DefaultSize(int size);		// Setter for default size of array

	// Functions
	int Size() const;	// Returns the size of the array

	// Operator overloading
	Array<T>& operator= (Array<T>& source);		// Assignment operator
	T& operator[] (int index);					// Square bracket operator
	const T& operator[] (int index) const;		// Const Square bracket operator

};

#ifndef ARRAY_CPP
#include "Array.cpp"
#endif	// ARRAY_CPP

#endif	// ARRAY_HPP