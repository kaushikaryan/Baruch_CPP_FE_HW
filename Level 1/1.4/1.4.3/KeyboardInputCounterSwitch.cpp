// KeyboardInputCounterSwitch.cpp
//
// C program to count various types of characters input via keyboard strokes
// using While loop and Switch Case
// 
// @author : Kaushik Aryan
// @date   : 21-04-2025

#include <stdio.h>

int main()
{
    int prev = NULL, curr = NULL;
    int charCount = 0, wordCount = 0, newLineCount = 0;
    printf("Enter some text:\n");
    while ((curr = getchar()) != 4)
    {
        switch (curr)
        {
            case 10:
            {
                newLineCount++;
                if (prev != NULL && prev != 32 && prev != 10)
                {
                    wordCount++; // Newline after Non-space && Non-newline character signals end of word
                }
            }
            break;
            case 32:
            {
                if (prev != NULL && prev != 32 && prev != 10)
                {
                    wordCount++; // Space after Non-space && Non-newline character signals end of word
                }
            }
            break;
            default:
                charCount++; // If not space or newline, count as character
        }
        prev = curr;
    }
    printf("Characters: %d, Words: %d, Newlines: %d", charCount, wordCount, newLineCount);
}
