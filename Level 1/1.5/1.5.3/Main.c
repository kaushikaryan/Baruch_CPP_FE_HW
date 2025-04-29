// Main.c
//
// C program to multiply a number by 2 and print
// the product
// 
// @author : Kaushik Aryan
// @date   : 24-04-2025

#include <stdio.h>
#include "Print.h"

int main()
{
    int i = NULL;
    printf("Enter a value for i : ");
    scanf_s("%d", &i);
    multiplyAndPrint(i);
    return 0;
}