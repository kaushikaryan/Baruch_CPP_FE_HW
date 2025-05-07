/**
*
* Save2File.c
*
* C program that reads characters from the keyboard
* and saves them to a file when the user hits enter.
* The program ends when the user enters ^A.
*
* @author   : Kaushik Aryan R
* @date     : 07-05-2025
* @version  : 1.0
*
**/

#include <stdio.h>		// Standard I/O functions
#include <string.h>		// String functions

// Save function declaration
void Save(char* p, char fileName[100]);

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
	char buffer[1000] = {},		// Buffer to store input line
		fileName[100] = {};		// String to store file name
	char* ptr = buffer;			// Pointer to current position in 

	// Take file name as input from user
	printf("Enter file name: ");
	gets_s(fileName);

	// Add .txt extension to file name
	strcat_s(fileName, ".txt");

	printf("Writing to file %s\n", fileName);

	// Read input characters until ^A is detected
	while ((c = getchar()) != 1)
	{
		// Call Save() when newline '\n' detected
		if (c == 10)
		{
			*ptr = '\0';			// Add null character to signal end of string
			Save(buffer, fileName);
			ptr = buffer;			// Reset pointer to beginning of buffer
		}
		else
		{
			// Store character in buffer and advance pointer
			*(ptr++) = c;
		}
	}

	// Print exit message
	printf("CTRL + A is a correct ending.");

	// Signal successful execution
	return 0;
}

/*
*
* Save function implementation
*
* Saves the contents of a character array into
* a text file with name given by user
*
* @param ptr		: Pointer to the character array
* @param fileName	: String with file name specified by user
*
*/

void Save(char* ptr, char fileName[100])
{
	FILE* f;
	// "a+" mode creates the file if it doesnt exist, 
	// or appends to the file if it already exists
	errno_t error = fopen_s(&f, fileName, "a+");   

	// Check if file opened successfully
	if (error != 0)
	{
		printf("Error: could not open %s", fileName);
		return;
	}

	// Write characters to file
	while (*ptr != '\0')
	{
		fputc(*(ptr++), f);
	}

	// Append newline
	fputc('\n', f);

	// Close the file
	fclose(f);

	return;
}
