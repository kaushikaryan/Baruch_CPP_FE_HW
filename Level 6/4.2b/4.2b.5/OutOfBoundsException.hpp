/**
*
* OutOfBoundsException.hpp
* 
* Header file for the OutOfBoundsException class.
*
* @author:  Kaushik Aryan R
* @date:    10-06-2025
* @version: 1.0
*
**/

#ifndef OutOfBoundsException_H
#define OutOfBoundsException_H

#include "ArrayException.hpp"
#include <iostream>
#include <sstream>

class OutOfBoundsException : public ArrayException
{
private:
	int m_index;	// Erroneous index

public:
	// Constructor that accepts index as argument
	OutOfBoundsException(int index) : ArrayException(), m_index(index) {};
	
	// Destructor
	virtual ~OutOfBoundsException() {};

	// Print error message
	std::string GetMessage() const
	{
		std::stringstream stream;

		stream << "Error: Index '" << m_index << "' is out of bounds" << std::endl;
		
		return stream.str();
	}
};

#endif	// OutOfBoundsException_H