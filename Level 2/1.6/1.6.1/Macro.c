// Macro.c
//
// C program to print a number(s)
// using macros
// 
// @author : Kaushik Aryan
// @date   : 27-04-2025

#include <stdio.h>
#include "Defs.h"

int main()
{
    int a = NULL, b = NULL;
    printf("Enter a number for a: ");
    scanf_s("%d", &a);
    printf("Enter a number for b: ");
    scanf_s("%d", &b);
    PRINT1(a);
    PRINT2(a, b);
}