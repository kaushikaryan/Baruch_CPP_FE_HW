// RightShift.cpp
// 
// C program to shift a number by 2 places
// 
// @author : Kaushik Aryan
// @date   : 03-05-2025

#include <stdio.h>

int main()
{
	// Initialize variable
	int num = 0;

	// Take input from user
	printf("Enter an integer: ");
	scanf_s("%d", &num);

	// Perform right shift
	num = num >> 2;
	printf("Shifted number is : %d\n", num);

	// Check if arithmetic or logical right shift
	if (num<0)
	{
		printf("Input number < 0. Arithmetic right shift.\n");
	}
	else
	{
		printf("Input number > 0. Logical right shift.\n");
	}
	return 0;
}
