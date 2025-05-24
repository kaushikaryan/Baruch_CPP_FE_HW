/**
*
* Main.cpp
*
* C++ program to test the Point class.
* The program initializes a point and demonstrates the use of
* a custom constructor and the explicit keyword
*
* @author:  Kaushik Aryan R
* @date:    23-05-2025
* @version: 1.0
*
**/

#include "Point.hpp"	// Header file for Point class
#include <iostream>

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
	// Initializing Point object
	Point p(1.0, 1.0);

	// Throws compiler error after declaring constructor as explicit
	/*if (p == 1.0) 
	{
		cout << "Equal!" << endl;
	}
	else
	{
		cout << "Not equal" << endl;
	}*/

	// Using contructor as conversion operator
	if (p == (Point)1.0)
	{
		cout << "Equal!" << endl;
	}
	else
	{
		cout << "Not equal" << endl;
	}

	// Return successful execution
	return 0;
}