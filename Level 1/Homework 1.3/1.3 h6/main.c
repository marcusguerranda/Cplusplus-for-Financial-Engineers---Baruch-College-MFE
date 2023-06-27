//Exercise 1.3.6

/* Task: Write a C-program that shifts any number two places to the right. Input should be an integer. Output should be 
the shifted result, as well as output an indication of whether a logical or arithmetic shift is performed (if a 1 or 0 is 
shifted in at the left side) for the inputted number. */

/* Structure: As per the Wikipedia link provided regarding logical shift, "most C and C++ implementations choose which right shift to perform
    depending on the type f integers being shifted: signed integers are shifted using the arithmetic shift, and unsignedintegers are shifted 
    using the logical shift." In effect, we know whether an arithmetic or logical shift is relevant as a function of the sign of the integer.
    Such idea will guide the program as follows:


*/

#include <stdio.h>

int main(){
    long long int i;
    long long int shift;   //Create two 

    printf("User, please provide a number: "); // Integer number requested ('long long' taking more possible values than 'int', 'short', or 'long').
    if (scanf("%lld", &i))   //Requesting an input from user.
    {
        shift = i>>2;    // Perform 2 bitwise shifts to the right.
        if(i>0)          // Determining whether arithmetic or logical shift is performed, as per explanation above.
        {
            printf("A logical shift was performed. The result is %lld", shift);
        }
        else
        {
            printf("An arithmetic shift was performed. The result is %lld", shift);
        }
        
    }
    else
    {
        printf("User, this was a wrong input. Please provide a signed or unsigned integer of your choice.");
    }

    return 0;
}


