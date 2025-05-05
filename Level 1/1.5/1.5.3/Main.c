// Main.c
//
// C program to multiply a number by 2 and print
// the product
// 
// @author : Kaushik Aryan
// @date   : 05-05-2025

#include <stdio.h>
#include "Print.h"

int main()
{
    // Initialize variable
    int i = 0;

    // Take input from user
    printf("Enter a value for i : ");
    scanf_s("%d", &i);

    // Function call
    print(i);
    return 0;
}