// PrintNumber.cpp
//
// C program to print a number
// using recursion
// 
// @author : Kaushik Aryan
// @date   : 05-05-2025

#include <stdio.h>

void printnumber(int num);

int main()
{
    // Initialize variable
    int num = 0;

    // Take input from user
    printf("Enter a number: ");
    scanf_s("%d", &num);

    printnumber(num);
}

void printnumber(int num)
{
    // Handle negative numbers
    if (num < 0) {
        num *= -1;
        putchar('-');
    }

    // Base case
    if (num < 10)
    {
        putchar('0' + num);
        return;
    }
    
    if (num / 10 > 0)
    {
        // Recursive call with n-1 digits from the left
        printnumber(num/10);
        putchar('0' + num % 10);
    }
}