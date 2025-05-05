// AssignmentOperators.cpp
// 
// C program to understand assignment operators
// 
// @author : Kaushik Aryan
// @date   : 03-05-2025

#include <stdio.h>
int main()
{
	int x = 2;
	int y;
	int z;
	x *= 3 + 2; // x = x * 5
	printf("x=%d\n", x); // x=10
	x *= y = z = 4; // z = 4; y = z; x = x * y
	printf("x=%d\n", x); // x=40
	x = y == z; // y==z => true (1); x = 1; 
	printf("x=%d\n", x); // x=1
	return 0;
}
