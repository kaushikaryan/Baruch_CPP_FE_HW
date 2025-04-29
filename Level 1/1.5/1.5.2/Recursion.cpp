// Recursion.cpp
//
// C program to print factorial of a number
// using recursion
// 
// @author : Kaushik Aryan
// @date   : 22-04-2025

#include <stdio.h>

int factorial(int num);

int main()
{
    int num = NULL;
    printf("Enter the first number: ");
    scanf_s("%d", &num);
    int ans = factorial(num);
    printf("The factorial of %d is: %d\n", num, ans);
}

int factorial(int num)
{
    if (num <= 1)
        return 1;`
    return num * factorial(num - 1);
}