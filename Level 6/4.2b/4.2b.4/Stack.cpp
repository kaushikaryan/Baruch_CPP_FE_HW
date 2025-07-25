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

// Default constuctor
template <typename T>
Stack<T>::Stack() : m_data(), m_current(0) {}

// Constuctor that accepts size as argument
template <typename T>
Stack<T>::Stack(int size) : m_data(size), m_current(0) {}

// Copy constructor
template <typename T>
Stack<T>::Stack(const Stack<T>& source) : m_data(source.m_data), m_current(source.m_current) {}

// Destructor
template <typename T>
Stack<T>::~Stack() {}

// Assignment operator
template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& source)
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
template<typename T>
int Stack<T>::getPos() const
{
	return m_current;
}

// Add element to the top of the stack
template<typename T>
void Stack<T>::Push(const T& element)
{
	m_data[m_current] = element;

	// Current position is not incremented if exception is thrown above
	m_current++;
}

// Return the element at top of the stack
template<typename T>
T Stack<T>::Pop()
{
	T element = m_data[m_current - 1];
	
	// Current position is not decremented if exception is thrown above
	m_current--;
	return element;
}

#endif	// STACK_CPP
