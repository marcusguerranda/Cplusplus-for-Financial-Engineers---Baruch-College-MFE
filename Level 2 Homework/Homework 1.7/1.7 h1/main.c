//main.c - Main source file
//Exercise 1.7.1
//
//Goal: Using pointers and creating a swap() function to swap inputted values between two variables. 
//
//Modification date: 11/18/2022

#include <stdio.h>

void Swap(double *a, double *b);    //Declare function Swap()

int main(){
    double i, j;                    

    printf("User, please provide two numbers which will allocated to variables i and j.");
    if(scanf("%lf %lf", &i, &j))    //Requesting user to give two inputs, whilst also catching possible wrong inputs
    {
        printf("Values inputted are i= %1.2lf and j= %1.2lf.\n", i, j);
        
        Swap(&i, &j);               //Summon swap function.

        printf("Values have been swapped. Now, i= %1.2lf and j= %1.2lf.\n", i,j);
    }
    else
    {
        printf("User, we have gone over this many times over the past exercises. Please provide the correct inputs requested");
    }

    return 0;
}

void Swap(double *a, double *b)     //Defining Swap() function that was declared line 10
{
    //Quite straigthforward manipulation to swap values by creating a temporary variable.
    double temp_var;

    temp_var = *a;
    *a = *b;
    *b = temp_var;
}