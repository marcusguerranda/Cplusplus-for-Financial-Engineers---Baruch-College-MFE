// Exercise 1.3.2

// Goal: Calculating surface of triangle, taking inputs from user. C-style.

#include <stdio.h>			

int main()
{
	double base, height, surface;  // Defining variables
    
    printf("User, please enter the base value of your triangle: ");   //Requesting user for base value.
    scanf("%lf", base);

	printf("User, please enter the height value of your triangle: ");  //Requesting user for height value.
	scanf("%lf", height);
	
    surface = (base*height) / 2.0; //Calculating surface area, and assigning to surface variable.
	printf("Surface area is: %f \n", surface);  //output with calculation

	return 0;
}