/**
*
* Main.cpp
* C++ program to test the Array class
*
* @author:  Kaushik Aryan R
* @date:    10-06-2025
* @version: 1.0
*
**/

#include <iostream>
#include "Stack.hpp"
#include "ArrayException.hpp"

// Using standard namespace to simplify code
using namespace std;

/*
*
* main function - entry point of the program
*
* @return 0 on successful execution
*
*/
int main()
{
	// Default constructor
	Stack<int> stack(10);

	// Populate stack with values
	for (int i = 1; i < 6; i++)
	{
		stack.Push(i);
	}

	// Copy constuctor
	Stack<int> stackCopy(stack);

	// Assignment operator
	Stack<int> stackAssignment = stackCopy;

	for (int i = 0; i < 5; i++)
	{
		cout << stackAssignment.Pop() << endl;
	}

	// Throws exception
	try
	{
		cout << stackAssignment.Pop() << endl;
	}
	catch (const ArrayException& e)
	{
		cout << e.GetMessage() << endl;
	}

	// Print value of m_current
	cout << "m_current: " << stackAssignment.getPos() << endl;

	// Return successful execution
	return 0;
}