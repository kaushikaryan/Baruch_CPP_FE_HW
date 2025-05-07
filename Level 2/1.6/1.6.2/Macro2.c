/**
*
* Macro2.c
*
* C program to create macros to compute the maximum value
* among variables and print it
* The program takes 3 double inputs from the user, 
* computes the maximum value among them using the MAX2 and MAX3 macros
* defined in Defs.h, and prints the result
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
* Takes user input for three doubles,computes the 
* maximum value among them using the MAX2 and MAX3 macros
* and prints the result
*
* @return 0 on successful execution
*
*/

int main()
{
    // Initialze variables
    double num1 = 0, num2 = 0, num3 = 0;

    // Take inputs from the user
    printf("Enter the first number: ");
    scanf_s("%lf", &num1);
    printf("Enter the second number: ");
    scanf_s("%lf", &num2);
    printf("Enter the third number: ");
    scanf_s("%lf", &num3);

    // Use MAX2 to get the maximum of 2 variables
    double max2 = MAX2(num1, num2);
    printf("Max (%10.2lf, %10.2lf) = %10.2lf\n", num1, num2, max2);

    // Use MAX3 to get the maximum of 3 variables
    double max3 = MAX3(num1, num2, num3);
    printf("Max (%10.2lf, %10.2lf, %10.2lf) = %10.2lf\n", num1, num2, num3, max3);

    // Indicate successful execution
    return 0;
}