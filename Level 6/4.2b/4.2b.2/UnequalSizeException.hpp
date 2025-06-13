/**
*
* UnequalSizeException.hpp
*
* Header file for the UnequalSizeException class.
*
* @author:  Kaushik Aryan R
* @date:    10-06-2025
* @version: 1.0
*
**/

#ifndef UnequalSizeException_H
#define UnequalSizeException_H

#include "ArrayException.hpp"
#include <iostream>
#include <sstream>

class UnequalSizeException : public ArrayException
{
private:
	std::string m_operation;	// Operation being performed on arrays

public:
	// Constructor that accepts string as input
	UnequalSizeException(std::string operation) : ArrayException(), m_operation(operation) {};

	// Destructor
	~UnequalSizeException() {};

	// Print error message
	std::string GetMessage() const
	{
		std::stringstream stream;

		stream << "Error: The '" << m_operation << "' operation cannot be performed on Arrays of unequal sizes" << std::endl;

		return stream.str();
	}
};

#endif	// UnequalSizeException_H