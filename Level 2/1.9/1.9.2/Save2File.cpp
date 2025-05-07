/**
*
* Save2File.c
*
* C program that reads characters from the keyboard
* and saves them to a file when the user hits enter.
* The program ends when the user enters ^A.
*
* @author   : Kaushik Aryan R
* @date     : 11-05-2025
* @version  : 1.1 (Removed string buffer implementation)
*
**/

#include <stdio.h>		// Standard I/O functions
#include <string.h>		// String functions

/*
*
* main function: Entry point of the program
*
* Reads characters from the keyboard and saves
* them to a file when the user hits enter.
* Exits when when user enters ^A.
*
* @return 0 on successful execution
*
*/

int main()
{
	// Initialize variables
	int c = 0;					// Variable to store input character
	char fileName[100] = {};	// String to store file name

	// Take file name as input from user
	printf("Enter file name: ");
	gets_s(fileName);

	// Add .txt extension to file name
	strcat_s(fileName, ".txt");

	printf("Writing to file %s\n", fileName);

	FILE* f;
	// "a+" mode creates the file if it doesnt exist, 
	// or appends to the file if it already exists
	errno_t error = fopen_s(&f, fileName, "a+");

	// Check if file opened successfully
	if (error != 0)
	{
		printf("Error: could not open %s", fileName);
		// Signal error
		return 1;
	}

	// Read input characters until ^A is detected
	while ((c = getchar()) != 1)
	{
		// Write characters to file
		fputc(c, f);
	}

	// Close the file
	fclose(f);

	// Print exit message
	printf("CTRL + A is a correct ending.");

	// Signal successful execution
	return 0;
}
