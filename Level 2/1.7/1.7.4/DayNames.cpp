/**
*
* DayNames.c
*
* C program to print the name of a day given its day number.
* The program initializes an array of strings to store
* the day names, and a function to display the 
* corresponding day.
*
* @author   : Kaushik Aryan R
* @date     : 07-05-2025
* @version  : 1.0
*
**/

#include <stdio.h>  // Standard I/O functions

// DayName function declaration
void DayName(char* days[], unsigned int dayNum);

/*
*
* main function: Entry point of the program
*
* Initializes the strings with the names
* of the days of the week.
* Takes input from the user and prints the
* name of the corresponding day.
*
* @return 0 on successful execution
*
*/

int main()
{
	// Initializing the names of the days
	char day1[] = "Sunday";
	char day2[] = "Monday";
	char day3[] = "Tuesday";
	char day4[] = "Wednesday";
	char day5[] = "Thursday";
	char day6[] = "Friday";
	char day7[] = "Saturday";

	// Initializing an array of pointers to day names
	char* days[] = { day1, day2, day3, day4, day5, day6, day7 };

	// Variable to store user input
	unsigned int dayNum = 0u;

	// Request input from user until valid input is received
	printf("Enter a number between 1 and 7: ");
	while (dayNum < 1 || dayNum > 7)
	{
		scanf_s("%d", &dayNum);

		// Validate input
		if (dayNum < 1 || dayNum > 7)
		{
			printf("Invalid input. Please enter a number between 1 and 7: ");
		}
	}

	// Call DayName() to print appropriate day of week
	DayName(days, dayNum);

	// Indicate successful execution
	return 0;
}

/*
*
* DayName function implementation
*
* Prints the name of day corresponding
* to given day number
*
* @param days  : Array of strings containing day names
* @param dayNum: Day number input by the user
*
*/

void DayName(char* days[], unsigned int dayNum)
{
	// Print day number and corresponding day name
	printf("The day corresponding to %d is %s", dayNum, days[dayNum - 1]); // Use (dayNum - 1) as array is 0 indexed
}