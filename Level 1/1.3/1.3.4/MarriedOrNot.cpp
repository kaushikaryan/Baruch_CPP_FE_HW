// MarriedOrNot.cpp
// 
// C program to check if someone is married usi9ng ternary operator
// 
// @author : Kaushik Aryan
// @date   : 20-04-2025

#include <stdio.h>

int main()
{
    int married = NULL;
	printf("Enter a number if you are married. Enter 0 if you are not.\n");
    scanf_s("%d", &married);
	printf("%s", married ? "You are married." : "You are not married."); // Using ternary operator to check 
	return 0;
}