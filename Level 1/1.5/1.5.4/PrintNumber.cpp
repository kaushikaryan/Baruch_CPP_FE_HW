// PrintNumber.cpp
//
// C program to print a number
// using recursion
// 
// @author : Kaushik Aryan
// @date   : 27-04-2025

#include <stdio.h>

void printnumber(int num);

int main()
{
    int num = NULL;
    printf("Enter a number: ");
    scanf_s("%d", &num);
    printnumber(num);
}

void printnumber(int num)
{
    if (num < 0) {
        num *= -1;
        putchar('-');
    }
    if (num < 10)
    {
        putchar('0' + num);
        return;
    }
    if (num / 10 > 0)
    {
        printnumber(num/10);
        putchar('0' + num % 10);
    }
}