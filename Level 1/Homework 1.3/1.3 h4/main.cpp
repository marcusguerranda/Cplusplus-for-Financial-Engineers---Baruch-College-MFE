// Exercise 1.3.4

// Goal: Using the ternary operator to determine whether someone is married or not.

/* Structure: Asking the user to input a value to indicate whether he/she is married or not, and passing this into 
              ternary operator. We also need to take into account possibility of mistyping non-integer, and printing a notice 
              that a wrong input was given, and to retry.*/

#include <stdio.h>

int main(){
    
    int married; //0 equal to 'not married', non-zero number equal to 'married'
    
    printf("User: please type 0 if not married, or else give 1 if married. \n");
	
    if (scanf("%d", &married))               //Verifying input of int type given or not.
	{
        printf( married ? "User, you are married.\n" : "User, you are not married.\n"); //Ternary operator
    }   
    else
    {
        printf("You need to provide an integer, and not other character types. \n");
    }
    
	return 0;
}
