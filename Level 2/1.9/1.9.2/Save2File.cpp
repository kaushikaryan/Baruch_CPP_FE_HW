// Save2File.cpp
//
// C Program to save inputted characters
// to a file when the user hits enter
// 
// @author : Kaushik Aryan
// @date   : 29-04-2025

#include <stdio.h>

int Save(char* p, char filename[100]);

int main()
{
	int c = NULL;
	char a[1000], filename[100];
	char* p = a;
	printf("Enter file name as <filename.txt>: ");
	gets_s(filename);
	while ((c = getchar()) != 1)
	{
		if (c == 10)
		{
			*p = '\0';
			int err = Save(a, filename);
			if (err == 1)
				break;
			p = a;
		}
		else
		{
			*(p++) = c;
		}
	}
	return 0;
}

int Save(char* a, char filename[100])
{
	FILE* f;
	errno_t error = fopen_s(&f, filename, "w");
	if (error != 0) {
		printf("File %s does not exist", filename);
		return 1;
	}
	while (*a != '\0')
		fputc(*(a++), f);
	return 0;
}
