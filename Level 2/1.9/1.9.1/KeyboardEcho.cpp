/**
*
* KeyboardEcho.c
*
* C program that reads characters from the keyboard
* and prints them on the screen when the user hits enter.
* The program ends when the user enters ^A.
*
* @author   : Kaushik Aryan R
* @date     : 09-05-2025
* @version  : 1.1 (Removed string buffer implementation)
*
**/

#include <stdio.h>  // Standard I/O functions

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

	// User enters line of text, and hits '\n'
	// The line of text is then read one character at a time by getchar()

	// Read input characters until ^A is detected
	while ((c = getchar()) != 1)
	{
		putchar(c);
	}

	// Print exit message
	printf("\nCTRL + A is a correct ending.");

	// Signal successful execution
	return 0;
}
