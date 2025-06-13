/**
*
* StackEmptyException.hpp
* Header file for the StackEmptyException class.
*
* @author:  Kaushik Aryan R
* @date:    13-06-2025
* @version: 1.0
*
**/

#ifndef StackEmptyException_H
#define StackEmptyException_H

#include "StackException.hpp"
#include <iostream>
#include <sstream>

class StackEmptyException : public StackException
{
public:
	// Constructor that accepts index as argument
	StackEmptyException() : StackException() {};

	// Destructor
	virtual ~StackEmptyException() {};

	// Print error message
	std::string GetMessage() const
	{
		std::stringstream stream;

		stream << "Error: Cannot perform operation, Stack is empty" << std::endl;

		return stream.str();
	}
};

#endif	// StackEmptyException_H