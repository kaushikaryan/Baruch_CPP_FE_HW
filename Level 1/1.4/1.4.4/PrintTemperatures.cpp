// PrintTemperatures.cpp
//
// C program to print temperatures in F and C
// using While loop
// 
// @author : Kaushik Aryan
// @date   : 21-04-2025

#include <stdio.h>

int main()
{
    int startTempF = 0, endTempF = 300, stepSize = 20;
    float tempC = NULL;
    printf("Farenheit\tCelsius\n");
    while (startTempF <= endTempF)
    {
        tempC = (startTempF - 32) * 5 / 9;
        printf("%d\t%10.1f\n", startTempF, tempC);
        startTempF += stepSize;
    }
}
