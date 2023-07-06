// TestPoint.hpp 
// Purpose: Main source file creating a program for the Point class, initializing point coordinates, and performing calculations on these class instances.
// Modification dates: 11/17/2022 
//
// REMARKS AND OBSERVATIONS: 
//
// Only minute changes have been made -- namely recalling SetX() and GetX() to X() (same for Y) given function overloading. Similar changes have been 
// made to DistanceOrigin() such that it was renamed Distance(). Output is the same as in the previous exercise. Here, we have also changed some functions to const and declared
// a const point.


#include "Point.hpp" //Header file that contains declarations
#include <iostream>


int main()
{
	const Point cp(1.5, 3.9);	//Const point declaration
	//cp.X(0.3);				//Compiler error

	std::cout << cp.X() << std::endl;	
	std::cout << cp.Y() << std::endl;	

	std::cout << cp.Distance() << std::endl;

	return 0;
}

