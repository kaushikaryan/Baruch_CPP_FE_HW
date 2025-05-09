/**
*
* 1.7.3.c
*
* C program to print values using
* indexing operator and arithmetic operations
* on character array pointers.
*
* @author   : Kaushik Aryan R
* @date     : 07-05-2025
* @version  : 1.0
*
**/

/* Predict what will be printed on the screen */
#include <stdio.h>
#define PRD(a) printf("%d", (a) ) // Print decimal
#define NL printf("\n"); // Print new line
// Create and initialse array
int a[] = { 0, 1, 2, 3, 4 };
int main()
{
	int i;
	int* p;
	for (i = 0; i <= 4; i++) PRD(a[i]);							// 1
	NL;
	for (p = &a[0]; p <= &a[4]; p++) PRD(*p);					// 2
	NL;
	NL;
	for (p = &a[0], i = 0; i <= 4; i++) PRD(p[i]);				// 3
	NL;
	for (p = a, i = 0; p + i <= a + 4; p++, i++) PRD(*(p + i)); // 4
	NL;
	NL;
	for (p = a + 4; p >= a; p--) PRD(*p);						// 5
	NL;
	for (p = a + 4, i = 0; i <= 4; i++) PRD(p[-i]);				// 6
	NL;
	for (p = a + 4; p >= a; p--) PRD(a[p - a]);					// 7
	NL;
	return 0;
}

/*
* 
* Expected Output:
* 1: 01234
* 2: 01234
*
* 3: 01234
* 4: 024
*
* 5: 43210
* 6: 43210
* 7: 43210
* 
*/