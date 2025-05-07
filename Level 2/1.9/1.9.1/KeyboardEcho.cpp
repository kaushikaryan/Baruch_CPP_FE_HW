/**
*
* KeyboardEcho.c
*
* C program that reads characters from the keyboard
* and prints them on the screen when the user hits enter.
* The program ends when the user enters ^A.
*
* @author   : Kaushik Aryan R
* @date     : 07-05-2025
* @version  : 1.0
*
**/

#include <stdio.h>  // Standard I/O functions

// Print function declaration
void Print(char* ptr);

/*
*
* main function: Entry point of the program
*
* Reads characters from the keyboard
* and prints them on the screen when the user hits enter.
* Exits when when user enters ^A.
*
* @return 0 on successful execution
*
*/

int main()
{
	// Initialize variables
	int c = 0; // Variable to store input character
	char buffer[1000] = {}; // Buffer to store input line
	char* ptr = buffer; // Pointer to current position in buffer

	// Read input characters until ^A is detected
	while ((c = getchar()) != 1)
	{
		// Call Print() when newline '\n' detected
		if (c == 10)
		{
			*ptr = '\0';	// Add null character to signal end of string
			Print(buffer);
			ptr = buffer;	// Reset pointer to beginning of buffer
		}
		else
		{
			// Store character in buffer and advance pointer
			*(ptr++) = c;
		}
	}

	// Print exit message
	printf("“CTRL + A is a correct ending.");

	// Signal successful execution
	return 0;
}

/*
*
* Print function implementation
*
* Prints the contents of a character array
*
* @param ptr  : Pointer to the character array
*
*/

void Print(char* ptr)
{
	// Print each character until null is encountered
	while (*ptr != '\0')
	{
		putchar(*(ptr++));
	}

	// Append new line
	putchar('\n');
}
