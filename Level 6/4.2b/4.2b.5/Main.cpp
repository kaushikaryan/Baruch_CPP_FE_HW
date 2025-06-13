/**
*
* Main.cpp
* C++ program to test the Array class
*
* @author:  Kaushik Aryan R
* @date:    13-06-2025
* @version: 1.0
*
**/

#include <iostream>
#include "Stack.hpp"
#include "StackEmptyException.hpp"
#include "StackFullException.hpp"


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
	Stack<int> stack(5);

	// Populate stack with values
	for (int i = 1; i < 6; i++)
	{
		stack.Push(i);
	}

	// Test StackFullException
	try
	{
		stack.Push(6);
	}
	catch (const StackException& e)
	{
		cout << e.GetMessage() << endl;
	}

	// Copy constuctor
	Stack<int> stackCopy(stack);

	// Assignment operator
	Stack<int> stackAssignment = stackCopy;

	for (int i = 0; i < 5; i++)
	{
		cout << stackAssignment.Pop() << endl;
	}

	// Test StackEmptyException
	try
	{
		cout << stackAssignment.Pop() << endl;
	}
	catch (const StackException& e)
	{
		cout << e.GetMessage() << endl;
	}

	// Return successful execution
	return 0;
}