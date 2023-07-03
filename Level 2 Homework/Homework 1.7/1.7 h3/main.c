//main.c - Main source file
//Exercise 1.7.3
//
//Goal: predict the output. Usage of pointers and reference variables.
//
//Modification date: 11/18/2022


#include <stdio.h>			

#define PRD(a) printf("%d", (a) )	//Defining PRD() function, which prints each integer variable a given in function's arguments
#define NL printf("\n"); 

int a[] = { 0, 1, 2, 3, 4};			//Array defined with 5 variables

int main()
{
	int i;
	int* p;

	for (i = 0; i <= 4; i++) PRD(a[i]); 			// Output:  01234
	NL; //newline

	for (p = &a[0]; p <= &a[4]; p++) PRD(*p);		// Output:  01234
	NL;//newline
	NL;//newline

	for (p = &a[0], i = 0; i <= 4; i++) PRD(p[i]);	// Output:  01234
	NL;//newline

	for (p = a, i = 0; p + i <= a + 4; p++, i++) PRD(*(p + i)); // Output:  024
	NL;//newline
	NL;//newline

	for (p = a + 4; p >= a; p--) PRD(*p);			// Output:  43210
	NL;//newline

	for (p = a + 4, i = 0; i <= 4; i++) PRD(p[-i]);	// Output:  43210
	NL;//newline

	for (p = a + 4; p >= a; p--) PRD(a[p - a]);		// Output:  43210
	NL;//newline

	return 0;
}