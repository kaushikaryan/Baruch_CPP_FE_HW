/**
*
* StackFullException.hpp
*
* Header file for the StackFullException class.
*
* @author:  Kaushik Aryan R
* @date:    13-06-2025
* @version: 1.0
*
**/

#ifndef StackFullException_H
#define StackFullException_H

#include "StackException.hpp"
#include <iostream>
#include <sstream>

class StackFullException : public StackException
{
public:
	// Constructor that accepts index as argument
	StackFullException() : StackException() {};

	// Destructor
	virtual ~StackFullException() {};

	// Print error message
	std::string GetMessage() const
	{
		std::stringstream stream;

		stream << "Error: Cannot perform operation, Stack is full" << std::endl;

		return stream.str();
	}
};

#endif	// StackFullException_H