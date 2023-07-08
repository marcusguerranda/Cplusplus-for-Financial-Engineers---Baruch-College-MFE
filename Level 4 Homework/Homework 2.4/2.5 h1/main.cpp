// main.cpp 
// Purposes:  Dynamically creating objects, using pointers, arrays of objects, and arrays of pointers.
// Modification dates: 11/22/2022 

#include "Point.hpp" 	//Header file that contains declarations for Point header file
#include "Line.hpp"		//Header file that contains declarations for Line header file
#include "Circle.hpp" 	//Header file that contains declarations for Circle header file
#include <iostream>

int main()
{
	Point *point1, *point2, *point3, *point4; 		//Creating pointers

	point1 = new Point;								//Default constructor
	point2 = new Point(3.2, 4.6);					//Constructor with coordinates
	point3 = new Point(1.0);						//Constructor using one variable, as seen in previous subexercise
	point4 = new Point(*point3); 					//Copy constructor, dereferencing *p3 prior.

	std::cout << "Distance of point 4 to its origin is: " << (*point4).Distance() << std::endl;				//Distance of temporary point 4 to its origin 
	std::cout << "Distance of point 3 to point 4 is:  " <<(*point3).Distance(*point4) << std::endl;			//Distanceof temporary point 3 to point 4
																											// This value is logically = 0, since we used the copy constructor to 
																											// make point 4 coordinates equal to those of point 3
	delete point1;
	delete point2;
	delete point3;
	delete point4;

	int LENGTH;												
	std::cout << "User, please give us the length of a an array of your choice." << std::endl;
	std::cin >> LENGTH;

	//Point a[LENGTH];	
	// Not possible -- arrays on the stack must have the size set at compile time

	Point *b;
	b = new Point [LENGTH]; 			//Array of points with given length by the user
	if (b == nullptr)					//Although not implemented for the first four pointers, creating a dynamic array could require more memory, 
	{									//and thus catching any 'nullptr' being sent back is a good idea (with an if-else condition)
		std::cout << "No memory available on the heap." << std::endl;
	}
	else
	{
		std::cout << "Dynamic array of pointers created on the heap." << std::endl;
	}
	delete [] b;
	std::cout << "Dynamic array of pointers destroyed." << std::endl;

	//NOTE TO SELF: It seems the only constructor that can be used when creating an array on the heap is the default constructor.
	
	return 0;
}