//Exercise 1.4.5

// Goal: Create a celsius to fahrenheit converter program, with certain given parameters, and a FOR-loop.

#include <stdio.h>

int main(){
    
    double start_celsius = 0, end_celsius= 19, fahrenheit, celsius;   //No need to ask for inputs; assignment does not ask for a malleable program.

    printf("Celcius \t  Fahrenheit \n");  //Create headers

    for (celsius = start_celsius; celsius <= end_celsius; celsius++ )
    {
        fahrenheit = (9.0 / 5.0)*celsius + 32.0; 
        printf("%10.1f %10.1f\n", celsius, fahrenheit);
    }

    return 0;
}