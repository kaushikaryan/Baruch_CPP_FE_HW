/**
*
* StackException.hpp
*
* Header file for the StackException base class.
*
* @author:  Kaushik Aryan R
* @date:    13-06-2025
* @version: 1.0
*
**/

#ifndef StackException_H
#define StackException_H

#include <iostream>

class StackException
{
public:
	StackException() {};			// Default constructor
	virtual ~StackException() {};	// Destructor

	virtual std::string GetMessage() const = 0;
};

#endif	// StackException_H