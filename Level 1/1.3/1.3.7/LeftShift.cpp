// LeftShift.cpp
// 
// C program to multiply a number 
// by a factor 2^n
// 
// @author : Kaushik Aryan
// @date   : 03-05-2025

#include <stdio.h>

int main()
{
    // Initialize variables
    int num = 0, power = 0;

    // Take inputs from user
    printf("Enter a number: ");
    scanf_s("%d", &num);
    printf("Enter power of 2: ");
    scanf_s("%d", &power);

    // Compute and print result
    long long result = (long)num << power;
    printf("The result of %d * 2^%d = %ld", num, power, result); 
    return 0;
}
