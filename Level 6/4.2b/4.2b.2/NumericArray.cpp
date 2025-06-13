/**
*
* NumericArray.cpp
* Implementation file for the NumericArray class
*
* @author:  Kaushik Aryan R
* @date:    10-06-2025
* @version: 1.0
*
**/

#ifndef NUMERIC_ARRAY_CPP
#define NUMERIC_ARRAY_CPP

#include "NumericArray.hpp"
#include "UnequalSizeException.hpp"

// Default constructor
template <typename T>
NumericArray<T>::NumericArray() : Array<T>() {};

// Constructor that takes size as input
template <typename T>
NumericArray<T>::NumericArray(int size) : Array<T>(size) {}

// Copy constructor
template <typename T>
NumericArray<T>::NumericArray(const NumericArray<T>& source) : Array<T>(source) {}

// Destructor
template <typename T>
NumericArray<T>::~NumericArray() {}

// Assignment operator
template <typename T>
NumericArray<T>& NumericArray<T>::operator= (const NumericArray<T>& source)
{
	if (this != &source)
	{
		// Call base class assignment operator
		Array<T>::operator=(source);
	}

	return *this;
}

// Scale array by factor
template <typename T>
NumericArray<T> NumericArray<T>::operator* (const T& factor) const
{
	NumericArray<T> resultArray(*this);

	// Scale every element of the array by the factor
	for (int i = 0; i < resultArray.Size(); i++)
		resultArray[i] *= factor;
	
	return resultArray;
}

// Sum of two arrays
template <typename T>
NumericArray<T> NumericArray<T>::operator+ (const NumericArray<T>& numericArray) const
{
	// If array sizes are not equal, throw UnequalSizeException
	if (Array<T>::Size() != numericArray.Size())
		throw UnequalSizeException("+");

	NumericArray<T> resultArray(*this);
	
	// Add corresponding elements of the arrays
	for (int i = 0; i < resultArray.Size(); i++)
		resultArray[i] += numericArray[i];

	return resultArray;
}

// Find dot product of two numeric arrays
template <typename T>
T NumericArray<T>::DotProduct(const NumericArray<T>& numericArray) const
{
	// If array sizes are not equal, throw UnequalSizeException
	if (Array<T>::Size() != numericArray.Size())
		throw UnequalSizeException("Dot Product");

	T dotProduct = 0;

	// Compute dot product
	for (int i = 0; i < Array<T>::Size(); i++)
		dotProduct += (*this)[i] * numericArray[i];

	return dotProduct;
}

#endif	// NUMERIC_ARRAY_CPP