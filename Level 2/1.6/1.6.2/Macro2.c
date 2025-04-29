// Macro2.c
//
// C program find maximum of 2 and 3 numbers
// using macros
// 
// @author : Kaushik Aryan
// @date   : 27-04-2025

#include <stdio.h>
#include "Defs.h"

int main()
{
    int a = NULL, b = NULL, c = NULL;;
    printf("Enter a number for a: ");
    scanf_s("%d", &a);
    printf("Enter a number for b: ");
    scanf_s("%d", &b);
    printf("Enter a number for c: ");
    scanf_s("%d", &c);
    int max1 = MAX2(a,b);
    printf("Max (%d, %d) = %d\n", a, b, max1);
    int max2 = MAX3(a,b,c);
    printf("Max (%d, %d, %d) = %d\n", a , b, c, max2);
}