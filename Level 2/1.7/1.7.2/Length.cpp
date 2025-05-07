/**
*
* Length.c
*
* C program to calculate the length of a string.
* The program accepts user input into a string (character array) 
* and calculates its length.
*
* @author   : Kaushik Aryan R
* @date     : 07-05-2025
* @version  : 1.0
*
**/

/* Calculate the length of a string */
#include <stdio.h>
#define MAXLINE 30
// String length declaration
int Length(char str[]);
int main()
{
	char string[MAXLINE + 1]; // Line of maxium 30 chars + \0
	int c; // The input character
	int i = 0; // The counter
	// Print intro text
	printf("Type up to %d chars. Exit with ^Z\n", MAXLINE);
	// Get the characters
	while ((c = getchar()) != EOF && i < MAXLINE)
	{
		// Append entered character to string
		string[i++] = (char)c;
	}
	string[i] = '\0'; // String must be closed with \0
	printf("String length is %d\n", Length(string));
	return 0;
}
/* Implement the Length() function here */

/*
*
* Length function implementation
*
* Calculates the length of a string by
* counting characters till '\0' is encountered.
*
* @param str	: String to measure length
* @return len	: Length of the string
*
*/

int Length(char str[])
{
	// Initialize counter to 0
	int len = 0;

	// Count characters until null character
	while (str[len] != '\0')
	{
		len++;
	}

	// If character is entered, newline must preceed ^Z
	// Subtract 1 from len to remove count of newline character
	return len > 0 ? (len - 1) : len;
}