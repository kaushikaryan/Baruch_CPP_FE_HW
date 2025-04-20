// RightShift.cpp
// 
// C program to shift a number by 2 places
// 
// @author : Kaushik Aryan
// @date   : 20-04-2025

#include <stdio.h>

int main()
{
	int num = NULL;
	printf("Enter an integer: ");
	scanf_s("%d", &num);
	num = num >> 2;
	printf("Shifted number is : %d\n", num);
	if (num<0)
		printf("Input number < 0. Arithmetic right shift.\n");
	else
		printf("Input number > 0. Logical right shift.\n");
	return 0;
}
