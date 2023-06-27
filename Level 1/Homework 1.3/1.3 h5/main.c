//Exercise 1.3.5

// Goal:A C-program that clearly shows the difference between post- and pre-incrementing substraction for variable i.

/* Structure: Asking for an input from the user, printing the given input, post- and pre-incrementing these.
              Also verifying to make sure the input provided is a number, and not of another type*/

#include <stdio.h>

int main()
{
	long long int original;
    long long int value_post;   
	long long int value_pre;

    printf("User, please assign a numerical value to x: ");
   
    if (scanf("%lld", &original))    // Checking if input is a number, or mistyped a character, or other invalid type
	{
        printf("Original value provided is: %lld \n", original);

        value_post = original--;
        printf("Post-increment value of x is still equal to it's original value (%lld), but then when negatively incremented, x is now equal to %lld. \n", value_post, original);

		original +=1; //Resetting 'original' to original input value, to show effect of pre-incrementing.

		value_pre = --original;
		printf("Pre-increment value of x is now equal to %lld, and original input is also equal to %lld. \n", value_pre, original); 
    }
	    
    else
	{
	    printf("User, please provide an appropriate number input. \n");
    }

	return 0;
}