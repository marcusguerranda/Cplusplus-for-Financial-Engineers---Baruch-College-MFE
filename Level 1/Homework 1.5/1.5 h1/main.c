// Exercise 1.5.1

// Goal: Writing a program with a minus() function such that it calculates given inputs in main() function.


#include <stdio.h>

int main()
{
	float a, b;
    float minus(float num_1, float num_2);        //Define the minus function.
	
    printf("User, please provide two numbers, whereby the second will be deducted from the first.\n");
	if ((scanf_s("%f", &a))&&(scanf_s("%f", &b)))  //Verifying inputs are numbers.
	{
		printf("The difference between %1.1f and %1.1f is approximately %1.1f.",a,b,minus(a, b));
	}
	else
	{
		printf("User, please input numbers and not anything else.");
	}
	return 0;
}

float minus(float num_1, float num_2)
{
	return num_1 - num_2;
}

