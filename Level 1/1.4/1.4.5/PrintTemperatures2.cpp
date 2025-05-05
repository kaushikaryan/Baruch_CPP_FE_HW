// PrintTemperatures2.cpp
//
// C program to print temperatures in C and F
// using For loop
// 
// @author : Kaushik Aryan
// @date   : 05-05-2025

#include <stdio.h>

int main()
{
    // Initialize variables
    int startTempC = 0, endTempC = 19, stepSize = 1, i = 0;
    double tempF = 0.0;

    // Print column names
    printf("Celsius\tFarenheit\n");

    for(i = startTempC; i <= endTempC; i+=stepSize)
    {
        // Convert Celsius to Farenheit
        tempF = startTempC *((double)9/5) + 32;

        // Print temperatures
        printf("%d\t%10.1f\n", startTempC, tempF);
        startTempC += stepSize;
    }
}
