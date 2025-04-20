// LeftShift.cpp
// 
// C program to multiply a number by a factor 2^n
// 
// @author : Kaushik Aryan
// @date   : 20-04-2025

#include <stdio.h>

int main()
{
    int num = NULL, power = NULL;
    printf("Enter a number: ");
    scanf_s("%d", &num);
    printf("Enter power of 2: ");
    scanf_s("%d", &power);
    printf("The result of %d * 2^%d = %ld", num, power, num << power); // Perform left shift
    return 0;
}
