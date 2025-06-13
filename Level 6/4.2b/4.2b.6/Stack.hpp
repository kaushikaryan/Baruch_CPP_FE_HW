/**
*
* Stack.cpp
* Header file for the Stack class
*
* @author:  Kaushik Aryan R
* @date:    12-06-2025
* @version: 1.0
*
**/

#ifndef STACK_H
#define STACK_H

#include "Array.hpp"

template <typename T, int size>
class Stack
{
private:
	Array<T> m_data;
	int m_current;

public:
	Stack();								// Default constuctor
	Stack(const Stack<T, size>& source);	// Copy constructor
	~Stack();								// Destructor

	Stack<T, size>& operator= (const Stack<T, size>& source);	// Assignment operator

	int getPos() const;				// Get current position (for debugging)
	void Push(const T& element);	// Add element to the top of the stack
	T Pop();						// Return the element at top of the stack
};

#ifndef STACK_CPP
#include "Stack.cpp"
#endif	// STACK_CPP

#endif	// STACK_H