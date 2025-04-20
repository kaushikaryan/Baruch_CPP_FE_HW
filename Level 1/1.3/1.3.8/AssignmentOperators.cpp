// AssignmentOperators.cpp
// 
// C program to understand assignment operators
// 
// @author : Kaushik Aryan
// @date   : 20-04-2025

#include <stdio.h>
int main()
{
	int x = 2;
	int y;
	int z;
	x *= 3 + 2; // x = x * 5
	printf("x=%d\n", x); // x=10
	x *= y = z = 4; // y = z = 4; x = x * y
	printf("x=%d\n", x); // x=40
	x = y == z; // y==z = 1
	printf("x=%d\n", x); // x=1
	return 0;
}
