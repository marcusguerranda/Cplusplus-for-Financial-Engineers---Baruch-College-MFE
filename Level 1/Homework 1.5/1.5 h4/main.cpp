// Exercise 1.5.4

// Goal: print a number inputted by using recursion, a printnumber() function, and putchar().


#include<stdio.h>

void printnumber(long long int num);   //Declaration

int main()
{
    long long int n;
	printf("Please enter an integer.\n");
	if (scanf("%lld", &n))                      // Catching any wrong inputs, other than numbers.
	{
		printnumber(n);
	}//Input an integer to be printed.
	
    else
	{
		printf("User, please provide an adequate number to print.\n");
	}
	return 0;
}

void printnumber(long long int num)//Set the recursive function to print the integer digit by digit.
{
	if (num<0)        //if inputted number is negative, convert it to a positive one, and then print negative sign in front of that converted number.
    { 
        num = -num;
        putchar('-');
    }
    
    if (num/10)
    { 
        printnumber(num/10);   //Recursive function
    }
    putchar(num %10 + '0' );
}
