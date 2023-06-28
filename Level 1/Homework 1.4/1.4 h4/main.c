// Exercise 1.4.4

// Goal: Print out a converting machine which converts Fahrenheit to the equivaent teperature in degrees Celcius.

// Structure: Ask for starting temperature in fahrenheit, ending temperature in fahrenheit, and step size. Use a WHILE LOOP.


#include <stdio.h>

int main(){

    double start_fahr, fahr, end_fahr, step_size, num_celsius;

    printf("User, please input the starting temperature in Fahrenheit degrees: \n");
    scanf("%lf", &start_fahr); //Given is 0     // Crucial: use reference variable and not variable itself, by nature of scanf.
    
    fahr = start_fahr;

    printf("User, please input the ending temperature in Fahrenheit degrees: \n");
    scanf("%lf", &end_fahr); //Given is 300

    printf("User, please input the step size between Fahrenheit degrees: \n");
    scanf("%lf", &step_size); //Given is 20

    printf("Fahrenheit \t Celsius \n");  // Creation of headers 

    while(fahr <= end_fahr)
    {
        num_celsius = (5.0 / 9.0) * (fahr - 32.0);   //Fahrenheit to Celcius temperature conversion formula
        printf("%10.1lf \t %10.1lf \n", fahr, num_celsius);
        fahr += step_size;
    }

    return 0;
}