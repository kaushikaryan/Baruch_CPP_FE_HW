// Subtraction.cpp
//
// C program to print difference of 2 numbers
// 
// @author : Kaushik Aryan
// @date   : 05-05-2025

#include <stdio.h>

// Function declaration
int minus(int a, int b);

int main()
{
    // Initialize variables
    int a = 0, b = 0;

    // Take inputs from user
    printf("Enter the first number: ");
    scanf_s("%d", &a);
    printf("Enter the second number: ");
    scanf_s("%d", &b);

    // Compute the difference
    int diff = minus(a, b);

    // Print result
    printf("The difference is: %d\n", diff);
}

// Function implementation
int minus(int a, int b)
{
    // Return the difference
    return a - b;
}