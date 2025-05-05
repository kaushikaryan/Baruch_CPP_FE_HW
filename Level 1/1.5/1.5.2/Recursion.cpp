// Recursion.cpp
//
// C program to print factorial of a number
// using recursion
// 
// @author : Kaushik Aryan
// @date   : 05-05-2025

#include <stdio.h>

// Function declaration
long long int factorial(long long int num);

int main()
{
    // Initialize variable
    int num = -1;

    // Request user to input a number, until valid input received
    while (num<0)
    {
        printf("Enter a non-negative number to compute its factorial: ");
        scanf_s("%d", &num);
    }

    // Compute factorial
    long long int ans = factorial(num); 

    // Print result
    printf("The factorial of %d is: %lld\n", num, ans);
}

// Function implementation
long long int factorial(long long int num)
{
    // Base case (0! = 1)
    if (num <= 1)
    {
        return 1;
    }
    // Recursive call
    return num * factorial(num - 1);
}