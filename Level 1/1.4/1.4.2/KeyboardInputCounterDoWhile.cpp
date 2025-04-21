// KeyboardInputCounterDoWhile.cpp
//
// C program to count various types of characters input via keyboard strokes
// using Do While loop
// 
// @author : Kaushik Aryan
// @date   : 21-04-2025

#include <stdio.h>

int main()
{
    int prev = NULL, curr = NULL;
    int charCount = 0, wordCount = 0, newLineCount = 0;
    printf("Enter some text:\n");
    do
    {
        if (curr == 10)
        {
            newLineCount++;
            if (prev != NULL && prev != 32 && prev != 10)
            {
                wordCount++; // Newline after Non-space && Non-newline character signals end of word
            }
        }
        else if (curr == 32 && prev != NULL && prev != 32 && prev != 10)
        {
            wordCount++; // Space after Non-space && Non-newline character signals end of word
        }
        else
        {
            charCount++; // If not space or newline, count as character
        }
        prev = curr;
    } while ((curr = getchar()) != 4);
    printf("Characters: %d, Words: %d, Newlines: %d", --charCount, wordCount, newLineCount); // Subtract one character, since ^D is counted as a character
}
