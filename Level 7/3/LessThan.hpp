/**
*
* LessThan.hpp
* 
* Header file of the LessThan class
*
* @author:  Kaushik Aryan R
* @date:    20-06-2025
* @version: 1.0
*
**/

#ifndef LESS_THAN_HPP
#define LESS_THAN_HPP

template <typename DataType>
class LessThan
{
private:
	DataType threshold;

public:
	LessThan(DataType value);	// Constructor that takes threshold as input
	~LessThan();				// Destructor

	bool operator()(DataType value) const;	// Operator overloading

	DataType GetThreshold() const;	// Getter
};

#ifndef LESS_THAN_CPP
#include "LessThan.cpp"
#endif	// LESS_THAN_CPP

#endif	// LESS_THAN_HPP