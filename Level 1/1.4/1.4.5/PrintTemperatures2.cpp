// PrintTemperatures2.cpp
//
// C program to print temperatures in C and F
// using For loop
// 
// @author : Kaushik Aryan
// @date   : 21-04-2025

#include <stdio.h>

int main()
{
    int startTempC = 0, endTempC = 19, stepSize = 1;
    double tempF = NULL;
    printf("Celsius\tFarenheit\n");
    for(int i = startTempC; i <= endTempC; i+=stepSize)
    {
        tempF = startTempC *((double)9/5) + 32;
        printf("%d\t%10.1f\n", startTempC, tempF);
        startTempC += stepSize;
    }
}
