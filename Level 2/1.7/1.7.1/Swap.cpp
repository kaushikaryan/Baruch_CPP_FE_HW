// Swap.cpp
//
// C program swap the values of 2 variables
// using pointers   
// 
// @author : Kaushik Aryan
// @date   : 27-04-2025

#include <stdio.h>

void swap(int *i, int *b);

int main()
{
    int i = 123, j = 456;
    swap(&i, &j);
    printf("Value of i: %d\nValue of j: %d", i, j);
}

void swap(int* i, int* j)
{
    int temp = *i;
    *i = *j;
    *j = temp;
}