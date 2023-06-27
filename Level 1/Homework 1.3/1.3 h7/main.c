//Exercise 1.3.7

// Goal: Write a C-program that efficiently mutiplies a number by a factor 2 to the power n.

/* Structure: this relates directly to logical shifts, which are useful to perform multiplication, or division of unsigned integers 
    by powers of two. As per Wikipedia: "Shifting left by n bits on a signed or unsigned binary number has the effect of multiplying it by 2^n."

    Hence, n left bitwise shifts will multiply our said number by 2^n, as per the clue given in the assignment question.

    Assumption: The power of 2 is positive, as per @APalley comment: "Yes, that is a fair assumption" on 10/1/15 (#post-160241)

*/

#include <stdio.h>

int main(){
    long long int num_given;   
    long long int num_pow;    

    printf("User, please provide any number you wish: \n");
    if(scanf("%lld", &num_given))                                  // Catch a wrong input before continuing with calculations with 'if' condition.
    {
        printf("User, please provide a second number 'n', such that we multiply your first number by 2^n: \n");
        if(scanf("%lld", &num_pow))
        {    
            num_given = num_given << num_pow;                      // n Left bitwise shift(s)
            printf("Result is: %lld", num_given);
        }
        else
        {
            printf("User, please provide a number. A wrong second input was given. \n");
        }
    }
    else
    {
        printf("User, please provide a number. A wrong first input was given.\n");
    }
    
    return 0;
}