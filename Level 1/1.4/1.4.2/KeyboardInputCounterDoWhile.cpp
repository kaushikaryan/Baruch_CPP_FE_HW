// KeyboardInputCounterDoWhile.cpp
//
// C program to count various types of characters input via keyboard strokes
// using Do While loop
// 
// @author : Kaushik Aryan
// @date   : 04-05-2025

#include <stdio.h>

int main()
{
    // Initialize variables
    int curr = 0, charCount = 0, wordCount = 0, newLineCount = 0,
        inWord = 0; // Flag to check if currently in a word

    // Take input from user
    printf("Enter some text:\n");
    do
    {
        // Count every input as a character
        charCount++;

        // Newline entered
        if (curr == 10)
        {
            newLineCount++;
            if (inWord)
            {
                // Newline after word signals end of word
                wordCount++;
                inWord = 0;
            }
        }
        // Space entered
        else if (curr == 32)
        {
            if (inWord)
            {
                // Space after word signals end of word
                wordCount++;
                inWord = 0;
            }
        }
        else
        {
            inWord = 1;
        }
    } while ((curr = getchar()) != 4);

    if (inWord)
    {
        // If ^D entered while in a word, count it
        wordCount++;
    }

    // Print result
    // Subtract one character from count, since ^D is counted as a character
    printf("Characters: %d, Words: %d, Newlines: %d", --charCount, wordCount, newLineCount); 
}
