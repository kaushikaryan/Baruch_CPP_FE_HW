// Print2.cpp
//
// C Program to print inputted characters
// when the user hits enter
// 
// @author : Kaushik Aryan
// @date   : 29-04-2025

#include <stdio.h>

void Print(char* p);

int main()
{
	int c = NULL;
	char a[1000];
	char* p = a;
	while ((c = getchar()) != 1)
	{
		if (c == 10) 
		{
			*p = '\0';
			Print(a);
			p = a;
		}
		else
		{
			*(p++) = c;
		}
	}
	return 0;
}

void Print(char* a)
{
	while (*a != '\0')
		putchar(*(a++));
	putchar('\n');
}
