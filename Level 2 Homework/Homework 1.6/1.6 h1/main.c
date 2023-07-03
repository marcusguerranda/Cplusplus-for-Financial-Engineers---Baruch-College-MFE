//main.c - Main source file
//Exercise 1.6.1
//
//Goal: Overloaded functions and printing numbers 
//
//Modification date: 11/18/2022

#include <stdio.h>
#include "Defs.h"               //Including header file with definitions for PRINT() overloaded functions     

int main()
{
    float a,b;
    printf("User, could you please give me two different numbers:");
    if(scanf("%f %f", &a, &b))  // Catch, as per usual, when the input is not a number (characters, punctuation, etc.)
    {
        PRINT1(a);              //When printing, I approximate to the second decimal, otherwise the printed numbers are too long and not aesthetic. See header file.
        PRINT2(a,b);   
    }
    else
    {
        printf("User, we have gone over so many exercises already. Please follow instructions, and give numbers...");
    }
    return 0;

}