//main.c - Main source file
//Exercise 1.6.2
//
//Goal: Overloaded functions and finding the maximum between either two inputs, or three inputs given by the user. 
//
//Modification date: 11/18/2022


#include <stdio.h>
#include "Defs.h"     //Including header file with definitions for PRINT() overloaded functions


int main()
{
    float x,y,z;
    printf("User, could you please give me three different numbers:");
    if(scanf("%f %f %f", &x, &y, &z)) // Catch, as per usual, when the input is not a number (characters, punctuation, etc.)
    {
        //When printing, I approximate to the second decimal, otherwise the printed numbers are too long and not aesthetic. See header file.
        printf("The biggest number between %1.2f and %1.2f is %1.2f.\n", x,y, MAX2(x,y));               //Print max number between x and y
        printf("The biggest number between %1.2f, %1.2f, and %1.2f is %1.2f.\n", x,y,z, MAX3(x,y,z));   //Printing max number between x,y, and z
    }
    else
    {
        printf("User, we have gone over so many exercises already. Please follow instructions, and give numbers...");
    }
    return 0;

}