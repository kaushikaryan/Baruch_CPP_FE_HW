// AreaofRightTriangle.cpp
// 
// C program to calculate and print area of right triangle
// 
// @author : Kaushik Aryan
// @date   : 20-04-2025

#include <stdio.h>

int main()
{
	double base = NULL, height = NULL;
	printf("Enter base of triangle: ");
	scanf_s("%lf", &base);
	printf("Enter height of triangle: ");
	scanf_s("%lf", &height);
	if (base > 0 && height > 0) // Check if inputs are valid
		printf("Area of triangle is: %lf", (base * height) / 2);
	else
		printf("Invalid inputs!");
	return 0;
}
