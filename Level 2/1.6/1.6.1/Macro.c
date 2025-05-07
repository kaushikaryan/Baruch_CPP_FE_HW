/**
*
* Macro.c
*
* C program to create macros and print variables
* The program takes 2 integer inputs from the user
* and prints them using the PRINT1 and PRINT2 macros
* defined in Defs.h
*
* @author   : Kaushik Aryan R
* @date     : 07-05-2025
* @version  : 1.0
*
**/

#include <stdio.h>  // Standard I/O functions
#include "Defs.h"   // Custom macros for printing

/*
*
* main function: Entry point of the program
*
* Takes user input for two integers and prints
* them using macros
*
* @return 0 on successful execution
*
*/

int main()
{
	// Initialize variables to 0
	int num1 = 0, num2 = 0;

	// Take inputs from user
	printf("Enter the first number: ");
	scanf_s("%d", &num1);
	printf("Enter the second number: ");
	scanf_s("%d", &num2);

	// Use PRINT1 macro to print variable num1
	PRINT1(num1);

	// Use PRINT2 macro to print variable num1 and num2
	PRINT2(num1, num2);

	// Indicate successful execution
	return 0;
}
