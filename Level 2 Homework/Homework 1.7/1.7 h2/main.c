//main.c - Main source file
//Exercise 1.7.2
//
//Goal: calculating the length of a string by creating Length() function, and use of pointers.
//
//Modification date: 11/18/2022

#include <stdio.h>
#define MAXLINE 30          //Defining MAXLINE to take the value 30; here, MAXLINE is the maximum of characters within the Length[] array defined below


int Length(char str[]);     //Declaring Length() function

int main()
{
    char string[MAXLINE+1]; //Line of maxium 30 chars + \0
    int c;                  //The input character
    int i=0;                //The counter

    printf("Type up to %d chars. Exit with ^Z. \n", MAXLINE);

    while ((c=getchar())!=EOF && c!=4 && c!= 26 && i<MAXLINE)   //User is requested inputs, stored in the array of characters, till he Ctrl+D, Ctrl+Z, or EOF 
    {

        string[i++]=(char)c;                                    //Incrementing index in the array variable with each input given by user
    }
    string[i]='\0';                                             //String must be closed with \0
    printf("String length is %d\n", Length(string));
    return 0;
}


int Length( char str[])
{
    int length = 0;                 // Length of string within str[]
    while(str[length] != '\0')      //Direct consequence of line 24, and string[i]='\0'.
    {
        length++;                   //Increment counter by 1 till str[length] = 0.
    }
    
    return length;  
}
                                                