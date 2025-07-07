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
#include <numeric>

/*
*
* main function - entry point of the program
*
* @return 0 on successful execution
*
*/

// Template function that returns sum of elements of container
template <typename Container>
double Sum(const Container& container)
{
	return std::accumulate(container.begin(), container.end(), 0.0);
}

// Template function that returns sum of values of elements of map
template <typename Key, typename Value>
double Sum(const std::map<Key, Value>& mapContainer)
{
	double sum = 0.0;
	for (typename std::map<Key, Value>::const_iterator i = mapContainer.begin(); i != mapContainer.end(); ++i)
		sum += i->second;
	return sum;
}

// Template function that returns sum of elements in an interval for a container
template <typename Iterator>
double Sum(Iterator begin, Iterator end)
{
	return std::accumulate(begin, end, 0.0);
}

// Template function that returns sum of values of elements in an interval for a map
template <typename Key, typename Value>
double Sum(typename std::map<Key, Value>::const_iterator begin, typename std::map<Key, Value>::const_iterator end)
{
	double sum = 0.0;
	for (;begin != end; begin++)
		sum += begin->second;
	return sum;
}


int main()
{
	// Wokring with Lists
	std::list<double> testList;

	// Populate list with data
	for (int i = 0; i < 5; i++)
		testList.push_back(i * 1.5);

	// Setting up the interval
	std::list<double>::const_iterator listBegin = testList.begin();
	std::list<double>::const_iterator listEnd = testList.end();
	std::advance(listBegin, 1);
	std::advance(listEnd, -2);

	// Print sums 
	std::cout << "Sum of testList: " << Sum(testList) << std::endl;
	std::cout << "Sum of interval[1-3] of testList: " << Sum(listBegin, listEnd) << std::endl;
	std::cout << std::endl;

	// Working with vectors
	std::vector<double> testVector;

	// Populate vector with data
	for (int i = 0; i < 5; i++)
		testVector.push_back(i * 1.5);

	// Setting up the interval
	std::vector<double>::const_iterator vectorBegin = testVector.begin();
	std::vector<double>::const_iterator vectorEnd = testVector.end();
	std::advance(vectorBegin, 1);
	std::advance(vectorEnd, -2);

	// Print sums
	std::cout << "Sum of testVector: " << Sum(testVector) << std::endl;
	std::cout << "Sum of interval[1-3] of testVector: " << Sum(vectorBegin, vectorEnd) << std::endl;
	std::cout << std::endl;

	// Working with maps
	std::map<std::string, double> testMap;

	// Populate map with data
	testMap["Apple"] = 1.25;
	testMap["Banana"] = 0.75;
	testMap["Mango"] = 1.50;
	testMap["Orange"] = 2.50;

	// Setting up the interval
	std::map<std::string, double>::const_iterator mapBegin = testMap.begin();
	std::map<std::string, double>::const_iterator mapEnd = testMap.end();
	std::advance(mapBegin, 1);
	std::advance(mapEnd, -1);

	// Print sums 
	std::cout << "Sum of testMap: " << Sum<std::string, double>(testMap) << std::endl;
	std::cout << "Sum of interval[1-2] of testMap: " << Sum<std::string, double>(mapBegin, mapEnd) << std::endl;
	std::cout << std::endl;

	// Return successful execution
	return 0;
}