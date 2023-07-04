//main.c - Main source file
//Exercise 1.8.1
//
//Goal: using putchar() and getchar(), as seen in lecture 1.9.1, to get input from user and print it back as long as user does not input ^A.
//
//Modification date: 11/18/2022


#include <stdio.h>

int main(){
    
    int c;
    printf("User, please input anything on your mind and press enter when you wish to see output. Press Ctrl+A when done. \n");
    
    while((c=getchar()) != 1) //User inputs a character and it is printed back, till eventually he ends program with Ctrl+A, = 1 in ASCII 
    {
        putchar(c);
    }

    if (c==1) printf("CTRL + A is a correct ending. \n"); //End of program and saying bye to user

    return 0;
}