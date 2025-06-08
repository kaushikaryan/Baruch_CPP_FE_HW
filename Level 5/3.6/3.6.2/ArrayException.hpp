/**
*
* ArrayException.hpp
* 
* Header file for the ArrayException base class.
*
* @author:  Kaushik Aryan R
* @date:    01-06-2025
* @version: 1.0
*
**/

#include <iostream>

class ArrayException
{
public:
	ArrayException() {};			// Default constructor
	virtual ~ArrayException() {};	// Destructor

	virtual std::string GetMessage() const = 0;
};