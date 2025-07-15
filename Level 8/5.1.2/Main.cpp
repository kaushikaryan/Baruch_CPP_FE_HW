/**
*
* Main.cpp
* C++ program to test Tuples
*
* @author:  Kaushik Aryan R
* @date:    28-06-2025
* @version: 1.0
*
**/

#include <boost/tuple/tuple.hpp>
#include <iostream>

// Declare a typedef to de-clutter code
typedef boost::tuple<std::string, unsigned int, double> Person;

// Defining a print function to print tuples of type Person
void Print(const Person& person)
{
	std::cout << "Name: " << person.get<0>()
		<< ", Age: " << person.get<1>()
		<< ", Length: " << person.get<2>()
		<< std::endl;
}

/*
*
* main function - entry point of the program
*
* @return 0 on successful execution
*
*/
int main()
{
	// Initialize three tuples
	Person person1 = boost::make_tuple("Kaushik", 24, 172.5);
	Person person2 = boost::make_tuple("Aryan", 24, 172.5);
	Person person3 = boost::make_tuple("Rajkumar", 53, 165);

	// Print the tuples using the above defined print function
	Print(person1);
	Print(person2);
	Print(person3);

	// Increment the age of one of the Person tuples
	person1.get<1>() += 1;

	// Print the updated tuple
	std::cout << "\nUpdated tuple:" << std::endl;
	Print(person1);

	// Return successful execution
	return 0;
}