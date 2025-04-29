// Struct.cpp
//
// C Program to define a struct
// and print it's contents
// 
// @author : Kaushik Aryan
// @date   : 29-04-2025

#include <stdio.h>

struct Article
{
	int articleNumber;
	int quantity;
	char description[20];
};

void Print(Article* article);

int main()
{
	struct Article a = { 181, 1, "A C program" };
	Print(&a);
	return 0;
}

void Print(Article* p)
{
	printf("Article Number: %d\nQuantity: %d\nDescription: %s\n", p->articleNumber, p->quantity, p->description);
}