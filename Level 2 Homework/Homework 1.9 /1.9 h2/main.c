//main.c - Main source file
//Exercise 1.8.1
//
//Goal: Altering the previous exercise's code to print out input into a file of choice.
//
//Modification date: 11/18/2022


#include <stdio.h>
#include <stdlib.h>
#define BUFFER 300          //Arbitrary length limit to the amount typed by the user before a whitespace encountered

int main()
{
    int c=0;                //Variable storing input characters requested from user after opening file.
    char namefile[BUFFER];  //File variable named to some random name, before being replaced by request from user.

    FILE* fp;               //Pointer variable for file.
    printf("User, please provide the name of the file you wish to open: \n");
    scanf("%s", namefile);  //Requesting file path  

    fp = fopen(namefile, "w+");  //"w+" --> Open file for read and write. If file does not exist, it is created first.
    
    if(fp ==NULL)
    {
        printf("User, something wrong happened and we could not open file you requested. Please investigate with IT. \n");
        exit(1);
    }
    else
    {   printf("User, your requested file has been opened now.\n");
        while((c=getchar()) != 1)   //User inputs a character and it is printed back, till eventually he ends program with Ctrl+A, = 1 in ASCII 
        {
            fputc(c, fp);           //Storing input into existing or created file
            putchar(c);             //Printing out input onto the console to verify what is being put into said file
        }
    }

    printf("CTRL + A is a correct ending. \n");
        
    fclose(fp);                     //Closing file
    return 0;

}

