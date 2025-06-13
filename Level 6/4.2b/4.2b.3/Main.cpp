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
#include "PointArray.hpp"
#include "Point.hpp"

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
	PointArray pointArray0;
	cout << "pointArray0.Size(): " << pointArray0.Size() << endl;

	// Constructor that takes size as input
	PointArray pointArray1(5);
	for (int i = 1; i < 6; i++)
		pointArray1[i-1] = Point(i, -i);	// [] operator

	cout << "pointArray1: " << pointArray1.ToString() << endl;

	cout << "pointArray1.Length(): " << pointArray1.Length() << endl;
	
	// Return successful execution
	return 0;
}