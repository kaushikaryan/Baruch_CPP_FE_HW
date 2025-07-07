/**
*
* Main.cpp
* 
* C++ program to test Function objects
*
* @author:  Kaushik Aryan R
* @date:    20-06-2025
* @version: 1.0
*
**/

#include <vector>
#include <iostream>
#include <algorithm>
#include "LessThan.hpp"

/*
*
* main function - entry point of the program
*
* @return 0 on successful execution
*
*/

// Global value for threshold
double globalThreshold = 12.0;

// Global function to check if value less than threshold
int LessThanThreshold(double input)
{
	return input < globalThreshold;
}

int main()
{	
	// Using global function
	
	// Working with vectors
	std::vector<double> testVector;

	// Populate vector with data
	for (int i = 0; i < 30; i++)
		testVector.push_back(i + 1);

	// Find count
	int count = std::count_if(testVector.begin(), testVector.end(), LessThanThreshold);

	// Print count
	std::cout << "Numbers less than globalThreshold (12): " << count << std::endl;
	std::cout << std::endl;

	// Using function object

	// Initialize function object
	LessThan<double> lessThanObj(16);

	// Find count
	count = std::count_if(testVector.begin(), testVector.end(), lessThanObj);

	// Print count
	std::cout << "Numbers less than lessThanObj (16): " << count << std::endl;
	std::cout << std::endl;

	// Return successful execution
	return 0;
}