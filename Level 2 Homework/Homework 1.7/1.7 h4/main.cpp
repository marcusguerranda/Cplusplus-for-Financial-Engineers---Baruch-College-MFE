//main.c - Main source file
//Exercise 1.7.4
//
//Goal: Creating a C program to print the name of the week given an allocated index number to each of the latter.
//
//Modification date: 11/18/2022

#include <stdio.h>

void DayName(unsigned int value);	//Declaring function, defined on line 28


int main()
{
	unsigned int day_numb;			 
    printf("User, please give a number referencing to a day of the week between 1 and 7: \n");
    if(scanf("%u", &day_numb) && day_numb<= 7)	//Requesting number for day of the week from one to seven, and unsigned such that respects constraints imposed.
	{
		DayName(day_numb);		
	}
	else
	{
		printf("User, you need to provide a number between 1 and 7 for this exercise.\n");
	}

	return 0;
}

void DayName(unsigned int day_numb)				//Function printing the name of day of the week associated to a number inputted by the user. 
{
	const char day_name[7][10] = {"Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}; //7 for the number of days, and 10 for the max number of characters given '\0'
	printf("Day %u is a %s.\n", day_numb, day_name[day_numb]);
	
	return;
}
