// Exercise 1.5.3

// Goal: Creating a source file and creating a function that multiplies the input given in the main file. I use decimal approximation for aethetic reasons.
         

#include <stdio.h>

int main()
{
    float num;
    void print(float x);
    
    printf("User, please provide any number you wish to multiply by 2:");
    scanf("%f", &num);

    print(num); // Everything is performed in the other source file to facilitate readability. Then source file is integrated in header file.
    
    return 0;
}

