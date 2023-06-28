#include <stdio.h>

int main()
{
    unsigned int a;
    long long int factorials(unsigned int num_1);   

    printf("User, please tell us what factorial you wish to get printed: /n");
    if(scanf("%u", &a))
    {
        printf("%u factorial is equal to: %lld", a, factorials(a));
    }
    else
    {
        printf("User, please provide an adequate number to be able to compute its factorial.");
    }

    return 0;
}


long long int factorials(unsigned int num_1)
{
    if (num_1 == 0 || num_1 == 1)
    {
        return 1;
    }
    else
    {
        return num_1 * factorials(num_1 - 1 );
    }
}