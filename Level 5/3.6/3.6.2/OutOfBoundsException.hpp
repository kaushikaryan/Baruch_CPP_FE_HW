/**
*
* OutOfBoundsException.hpp
* 
* Header file for the OutOfBoundsException class.
*
* @author:  Kaushik Aryan R
* @date:    01-06-2025
* @version: 1.0
*
**/

#include "ArrayException.hpp"
#include <iostream>
#include <sstream>

class OutOfBoundsException : public ArrayException
{
private:
	int m_index;

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
