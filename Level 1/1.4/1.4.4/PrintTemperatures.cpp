// PrintTemperatures.cpp
//
// C program to print temperatures in F and C
// using While loop
// 
// @author : Kaushik Aryan
// @date   : 05-05-2025

#include <stdio.h>

int main()
{
    // Initialize variables
    int startTempF = 0, endTempF = 300, stepSize = 20;
    float tempC = 0.0;

    // Print column names
    printf("Farenheit\tCelsius\n");

    while (startTempF <= endTempF)
    {
        // Convert Farenheit to Celsius
        tempC = (startTempF - 32) * 5 / 9;

        // Print temperatures
        printf("%d\t%10.1f\n", startTempF, tempC);
        startTempF += stepSize;
    }
}
