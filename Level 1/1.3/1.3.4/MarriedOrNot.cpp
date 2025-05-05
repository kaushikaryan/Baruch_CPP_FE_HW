// MarriedOrNot.cpp
// 
// C program to check if someone is married 
// using ternary operator
// 
// @author : Kaushik Aryan
// @date   : 03-05-2025

#include <stdio.h>

int main()
{
    // Initialize variable
	int married = -1;

	// Take input from user
	printf("Enter a number if you are married. Enter 0 if you are not.\n");
    scanf_s("%d", &married);

	// Use ternary operator to compute if user is married
	printf("%s", married ? "You are married." : "You are not married.");
	return 0;
}