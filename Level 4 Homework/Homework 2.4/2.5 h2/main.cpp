// main.cpp 
// Purposes: Dynamically creating objects, using pointers, arrays of objects, and arrays of pointers.
// Modification dates: 11/22/2022 


#include "Point.hpp" 	//Header file that contains declarations for Point header file
#include "Line.hpp"		//Header file that contains declarations for Line header file
#include "Circle.hpp" 	//Header file that contains declarations for Circle header file
#include <iostream>

int main()
{
	
//CREATE AN ARRAY OF POINT POINTERS WITH 3 ELEMENTS ON THE HEAP

	int LENGTH = 3;

	Point* *pp = new Point*[LENGTH];		//** pointer to pointers to Points,  notation (two * together basically) -- creating an array of three Point pointers on the heap

//CREATE FOR EACH ELEMENT IN THE ARRAY A POINT ON THE HEAP

	pp[0] = new Point();					//Creating Point with default constructor
	pp[1] = new Point(3.2);					//Creating Point with explicit constructor (one value give, and allocated to both x and y)
	pp[2] = new Point(3.4, 92.1);			//Creating Point with overloaded constructor with two inputs

//ITERATE THE ARRAY AND PRINT EACH POINT IN THE ARRAY

	for(int i = 0; i<LENGTH; i++)
	{
		std::cout << "Point " << i+1 << " is: " << *pp[i] << std::endl;		//Printing a description of each Point coordinates on the heap using for-loop and pointers.
	}

//ITERATE THE ARRAY AGAIN AND DELETE EACH POINT IN THE ARRAY

	for(int i = 0; i<LENGTH; i++)			//Note that the variable of i is local to the scope and not global (as in C) -- see notes. 
	{
		std::cout << "Point " << i+1 << " is being deleted from the heap." << std::endl;
		delete pp[i];
	}

//DELETE THE ARRAY ITSELF

	delete [] pp;
	return 0;
}