/**
*
* Main.cpp
* C++ program to test STL
*
* @author:  Kaushik Aryan R
* @date:    20-06-2025
* @version: 1.0
*
**/

#include <list>
#include <vector>
#include <map>
#include <iostream>
#include <string>

/*
*
* main function - entry point of the program
*
* @return 0 on successful execution
*
*/

int main()
{	
	// Wokring with Lists
	std::list<double> testList;

	// Populate list with data
	for (int i = 0; i < 5; i++)
		testList.push_back(i * 1.5);

	// Using front() and back() functions to access first and last elements respectively
	std::cout << "Front of testList: " << testList.front() << std::endl;
	std::cout << "Back of testList: " << testList.back() << std::endl;
	std::cout << std::endl;

	// Working with vectors
	std::vector<double> testVector;

	// Populate vector with data
	for (int i = 0; i < 5; i++)
		testVector.push_back(i * 1.5);

	// Using index operator to access some elements
	std::cout << "Element at index 2 of testVector: " << testVector[2] << std::endl;
	std::cout << "Element at index 4 of testVector: " << testVector[4] << std::endl;
	std::cout << "Initial size of vector: " << testVector.size() << std::endl;
	std::cout << std::endl;

	// Making vector grow by adding elements
	for (int i = 5; i < 11; i++)
		testVector.push_back(i * 2.0);

	// Using index operator to access some elements
	std::cout << "Element at index 7 of testVector: " << testVector[7] << std::endl;
	std::cout << "Element at index 9 of testVector: " << testVector[9] << std::endl;
	std::cout << "Size of vector after adding more elements: " << testVector.size() << std::endl;
	std::cout << std::endl;

	// Working with maps
	std::map<std::string, double> testMap;
	
	// Populate map with data
	testMap["Apple"] = 1.25;
	testMap["Mango"] = 1.50;
	testMap["Orange"] = 2.50;
	testMap["Banana"] = 0.75;

	// Accessing elements of map using square bracket operator
	std::cout << "Price of Apple: $" << testMap["Apple"] << std::endl;
	std::cout << "Price of Orange: $" << testMap["Orange"] << std::endl;
	std::cout << std::endl;

	// Return successful execution
	return 0;
}