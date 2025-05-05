// AreaofRightTriangle.cpp
// 
// C program to calculate and print 
// area of right triangle
// 
// @author : Kaushik Aryan
// @date   : 03-05-2025

#include <stdio.h>

int main()
{
	// Initialize variables
	 double base = 0, // base of triangle
		 height = 0; // height of triangle
	
	// Take inputs from the user for length of base and height
	printf("Enter base of triangle: ");
	scanf_s("%lf", &base);
	printf("Enter height of triangle: ");
	scanf_s("%lf", &height);

	// Validate and print area of triangle
	if (base > 0 && height > 0) 
	{
		printf("Area of triangle is: %lf", (base * height) / 2);
	}
	else
	{
		printf("Invalid inputs!");
	}
	return 0;
}
