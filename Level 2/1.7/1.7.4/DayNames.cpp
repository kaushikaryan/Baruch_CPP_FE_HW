// DayNames.cpp
//
// C Program to print day 
// based on input
// 
// @author : Kaushik Aryan
// @date   : 29-04-2025

#include <stdio.h>

void DayName(char* days[], int dayNum);

int main()
{	
	char day1[] = "Sunday";
	char day2[] = "Monday";
	char day3[] = "Tuesday";
	char day4[] = "Wednesday";
	char day5[] = "Thursday";
	char day6[] = "Friday";
	char day7[] = "Saturday";
	char* days[] = {day1, day2, day3, day4, day5, day6, day7};
	int dayNum = NULL;
	while (dayNum < 1 || dayNum > 7)
	{
		printf("Enter a number between 1 and 7: ");
		scanf_s("%d", &dayNum);
	}
	DayName(days, dayNum);
	return 0;
}

void DayName(char* days[], int dayNum)
{
	printf("The day corresponding to %d is %s", dayNum, days[dayNum-1]);
}