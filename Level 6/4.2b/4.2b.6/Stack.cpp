/**
*
* Stack.cpp
* Implementation file for the Stack class
*
* @author:  Kaushik Aryan R
* @date:    12-06-2025
* @version: 1.0
*
**/

#ifndef STACK_CPP
#define STACK_CPP

#include <iostream>
#include "Stack.hpp"
#include "ArrayException.hpp"
#include "StackEmptyException.hpp"
#include "StackFullException.hpp"

// Default constuctor
template <typename T, int size>
Stack<T, size>::Stack() : m_data(size), m_current(0) {}

// Copy constructor
template <typename T, int size>
Stack<T, size>::Stack(const Stack<T, size>& source) : m_data(source.m_data), m_current(source.m_current) {}

// Destructor
template <typename T, int size>
Stack<T, size>::~Stack() {}

// Assignment operator
template <typename T, int size>
Stack<T, size>& Stack<T, size>::operator=(const Stack<T, size>& source)
{
	// Check if source is not equal to current object
	if (this != &source)
	{
		m_data = source.m_data;
		m_current = source.m_current;
	}

	return *this;
}

// Get current position (for debugging)
template <typename T, int size>
int Stack<T, size>::getPos() const
{
	return m_current;
}

// Add element to the top of the stack
template <typename T, int size>
void Stack<T, size>::Push(const T& element)
{
	try 
	{
		m_data[m_current] = element;

		// Current position is not incremented if exception is thrown above
		m_current++;
	}
	catch (...)
	{
		throw StackFullException();
	}
}

// Return the element at top of the stack
template <typename T, int size>
T Stack<T, size>::Pop()
{
	try
	{
		return m_data[--m_current];
	}
	catch (...)
	{
		// Set current index to 0 when exception is thrown
		m_current = 0;
		throw StackEmptyException();
	}
}

#endif	// STACK_CPP
