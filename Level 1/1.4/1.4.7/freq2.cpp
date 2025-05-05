// freq2.c
//
// C program to count frequency of different 
// numbers and characters
// 
// @author : Kaushik Aryan
// @date   : 05-05-2025

#include <stdio.h>

int main()
{
    // Initialize variables
    int curr = -1, count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0, countOther = 0;

    printf("Enter some numbers:\n");

    // Logic to increment count of characters entered
    while ((curr = getchar()) != EOF)
    {
        switch (curr)
        {
        case 48:
            count0++;
            break;
        case 49:
            count1++;
            break;
        case 50:
            count2++;
            break;
        case 51:
            count3++;
            break;
        case 52:
            count4++;
            break;
            // Other characters
        default:
            countOther++;
        }
    }

    printf("Count of 0s:%d\nCount of 1s:%d\nCount of 2s:%d\nCount of 3s:", count0, count1, count2);

    // Logic to print count of '3' in words
    switch (count3)
    {
        case 0:
            printf("The number three appears zero times\n");
            break;
        case 1:
            printf("The number three appears one time\n");
            break;
        case 2:
            printf("The number three appears two times\n");
            break;
        default:
            printf("The number three appears more than two times\n");
    }
    printf("Count of 4s:%d\nCount of other characters:%d\n", count4, countOther);
}
