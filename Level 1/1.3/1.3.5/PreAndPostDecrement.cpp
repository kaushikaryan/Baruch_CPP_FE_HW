// PreAndPostDecrement.cpp
// 
// C program to differentiate between 
// pre and post decrement unary operators
// 
// @author : Kaushik Aryan
// @date   : 03-05-2025

#include <stdio.h>

int main()
{
    // Initialize variable
    int i = 10;

	printf("i = %d\n", i); // i = 10

    // Pre-decrement: decrement i before using it
    printf("--i = %d\n",--i); //  (i = i - 1 = 9), then print i

    // Post-decrement: use i, then decrement it
    printf("i-- = %d\n", i--); // print i, then (i = i - 1 = 8)

	printf("i = %d\n", i); // i = 8
    return 0;
}
