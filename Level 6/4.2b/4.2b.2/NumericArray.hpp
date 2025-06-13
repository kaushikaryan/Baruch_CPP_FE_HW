/**
*
* NumericArray.hpp
* Header file for NumericArray class
*
* @author:  Kaushik Aryan R
* @date:    10-06-2025
* @version: 1.0
*
**/

#ifndef NUMERIC_ARRAY_H
#define NUMERIC_ARRAY_H

#include "Array.hpp"

template <typename T>
class NumericArray : public Array<T>
{
public:
	NumericArray();									// Default constructor
	NumericArray(int size);							// Constructor that takes size as input
	NumericArray(const NumericArray<T>& source);	// Copy constructor
	~NumericArray();								// Destructor

	// Operator overloading
	NumericArray<T>& operator= (const NumericArray<T>& source);				// Assignment operator
	NumericArray<T> operator* (const T& factor) const;						// Scale array by factor
	NumericArray<T> operator+ (const NumericArray<T>& numericArray) const;	// Sum of two arrays

	// Other functions
	T DotProduct (const NumericArray<T>& numericArray) const;	// Find dot product of two numeric arrays
};

#ifndef NUMERIC_ARRAY_CPP
#include "NumericArray.cpp"
#endif	// NUMERIC_ARRAY_CPP 

#endif	// NUMERIC_ARRAY_H
