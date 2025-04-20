// PreAndPostDecrement.cpp
// 
// C program to differentiate between pre and post decrement unary operators
// 
// @author : Kaushik Aryan
// @date   : 20-04-2025

#include <stdio.h>

int main()
{
    
    int i = 10;
	printf("i = %d\n", i); // i = 10
    printf("--i = %d\n",--i); // --i = 10 - 1 = 9
    printf("i-- = %d\n", i--); // i-- = 9
    // 9 - 1 = 8
	printf("i = %d\n", i); // i = 8
    return 0;
}
