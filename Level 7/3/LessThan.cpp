/**
*
* LessThan.cpp
* 
* Implementation file for the LessThan class
*
* @author:  Kaushik Aryan R
* @date:    20-06-2025
* @version: 1.0
*
**/

#ifndef LESS_THAN_CPP
#define LESS_THAN_CPP

#include "LessThan.hpp"

// Constructor that takes threshold as input
template <typename DataType>
LessThan<DataType>::LessThan(DataType value) : threshold(value) {}

// Destructor
template <typename DataType>
LessThan<DataType>::~LessThan() {}

// Operator overloading
template <typename DataType>
bool LessThan<DataType>::operator()(DataType value) const
{
	return value < threshold;
}

// Getter
template <typename DataType>
DataType LessThan<DataType>::GetThreshold() const
{
	return threshold;
}

#endif	// LESS_THAN_CPP