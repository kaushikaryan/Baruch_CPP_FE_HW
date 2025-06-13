/**
*
* Array.hpp
* Header file for Array class
* 
* @author:  Kaushik Aryan R
* @date:    09-06-2025
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
	T* m_data;
	int m_size;

public:
	Array();						// Default constructor
	Array(int size);				// Constructor that accepts size as argument
	Array(const Array<T>& array);	// Copy constructor
	~Array();						// Destructor

	// Getter
	T& GetElement(int index) const;	// Getter for element if the array at index

	// Setter
	void SetElement(int index, const T& t);	// Setter for element if the array at index

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

/*

by placing the following code at the end of the array header file, but before the header
file’s #endif, the client can keep including the header file for template classes instead of the
source file.Can you explain how this works ? :
#ifndef Array_cpp      
#include "Array.cpp" 
#endif

This works because the aforementioned code snippet includes the Array.cpp file when Array.hpp is first included.
We do not have to worry about circular imports (even though Array.cpp includes Array.hpp) because we have a similar 
#ifndef-include-endif block present that prevents multiple inclusions of the Array.hpp file.

*/