/**
*
* Main.cpp
* C++ program to test uniform distribution
*
* @author:  Kaushik Aryan R
* @date:    05-07-2025
* @version: 1.0
*
**/

#include <boost/random.hpp>
#include <iostream>
#include <map>

/*
*
* main function - entry point of the program
*
* @return 0 on successful execution
*
*/
int main()
{
	// Throwing dice. 
	// Mersenne Twister. 
	boost::random::mt19937 myRng;

	// Set the seed. 
	myRng.seed(static_cast<boost::uint32_t> (std::time(0)));

	// Uniform in range [1,6] 
	boost::random::uniform_int_distribution<int> six(1, 6);

	std::map<int, long> statistics;	// Structure to hold outcome + frequencies 
	int outcome;					// Current outcome

	// Generate an initial dice outcome
	outcome = six(myRng);

	int n = 0;
	std::cout << "How many trials? ";
	std::cin >> n;	// Read the number of trials from user input

	// Simulate rolling the dice 'n' times
	for (int i = 0; i < n; i++)
	{
		outcome = six(myRng);
		statistics[outcome]++;
	}

	// Display the percentage and count of each outcome (1 to 6)
	for (int i = 1; i <= 6; i++)
		std::cout << "Trial " << i << " has " 
		<< 100 * (double)statistics[i] / (double)n
		<< "% outcomes" << std::endl;

	// Return successful execution
	return 0;
}