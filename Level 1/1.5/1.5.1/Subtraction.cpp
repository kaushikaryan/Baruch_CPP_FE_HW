// Subtraction.cpp
//
// C program to print difference of 2 numbers
// 
// @author : Kaushik Aryan
// @date   : 22-04-2025

#include <stdio.h>

int minus(int a, int b);

int main()
{
    int a = NULL, b = NULL;
    printf("Enter the first number: ");
    scanf_s("%d", &a);
    printf("Enter the second number: ");
    scanf_s("%d", &b);
    int diff = minus(a, b);
    printf("The difference is: %d\n", diff);
}

int minus(int a, int b)
{
    return a - b;
}