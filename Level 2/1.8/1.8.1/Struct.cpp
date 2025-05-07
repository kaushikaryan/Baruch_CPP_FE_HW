/**
*
* Struct.c
*
* C program to declare a struct called Article
* and print its contents.
*
* @author   : Kaushik Aryan R
* @date     : 07-05-2025
* @version  : 1.0
*
**/

#include <stdio.h>  // Standard I/O functions

/*
*
* Article struct definition
*
* Contains information about an Article:
* - article number
* - quantity
* - description
*
*/
struct Article
{
	int articleNumber;
	int quantity;
	char description[20];
};

// Print function declaration
void Print(struct Article* article);

/*
*
* main function: Entry point of the program
*
* Initializes an object of type struct Article
* and prints its contents.
*
* @return 0 on successful execution
*
*/

int main()
{
	// Initialize an Article with values
	struct Article a = { 181, 1, "A C program" };

	// Print its contents
	Print(&a);

	// Indicate successful execution
	return 0;
}

/*
*
* Print function implementation
*
* Prints the contents of struct Article
*
* @param p  : Pointer to an object of type Article
*
*/

void Print(struct Article* p)
{
	// Print all fields of the Article structure
	printf("Article Number: %d\nQuantity: %d\nDescription: %s\n", p->articleNumber, p->quantity, p->description);
}