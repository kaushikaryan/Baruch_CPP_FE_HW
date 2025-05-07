/**
*
* Swap.c
*
* C program to swap the values of two integer variables.
* The program initializes two integer variables i and j,
* and then swaps their values using a function with
* pointer parameters
*
* @author   : Kaushik Aryan R
* @date     : 07-05-2025
* @version  : 1.0
*
**/

#include <stdio.h>  // Standard I/O functions

// swap function declaration
void swap(int *pt1, int *pt2);

/*
*
* main function: Entry point of the program
*
* Initializes two integer variables i and j,
* swaps their values using the swap() function,
* and prints their values
*
* @return 0 on successful execution
*
*/

int main()
{
    // Initialize variables
    int i = 123, j = 456;
    printf("Initial values:\ni: %d\nj: %d\n", i, j);

    // Use swap() to swap the values of variabes i and j
    swap(&i, &j);

    // Print the result
    printf("Values after swap:\ni: %d\nj: %d\n", i, j);

    // Indicate successful execution
    return 0;
}

/*
*
* swap function implementation
*
* Swaps the values of two integer values 
* using pointers
*
* @param i  : Pointer to first integer
* @param j  : Pointer to second integer
*
*/

void swap(int* pt1, int* pt2)
{
    // Assign dereferenced value of pt1 to a temporary variable
    int temp = *pt1;

    // Assign the dereferenced value of pt2 to pt1
    *pt1 = *pt2;

    // Assign the dereferenced value of pt1 (from temporary variable) to pt2
    *pt2 = temp;
}