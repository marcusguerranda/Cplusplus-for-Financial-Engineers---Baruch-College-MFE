// main.cpp 
// Purposes: Testing different operator overloadings as seen in Level 4 lectures (assignment operator, scaling, adding, etc.) and seeing how this affects instances.
// Modification dates: 11/22/2022 

#include "Point.hpp" 	//Header file that contains declarations for Point header file
#include "Line.hpp"		//Header file that contains declarations for Line header file
#include "Circle.hpp" 	//Header file that contains declarations for Circle header file
#include <iostream>

int main()
{
/*
	Point p(1.0, 1.0);
	if (p==1.0) 
	{
		std::cout << "Equal!" << std::endl;
	}
	else 
	{
		std::cout << "Not equal" << std::endl;
	}
*/

// The code above will, almost paradoxically, compile indeed. At first, this may seem strange given that we are giving two arguments, and we have only
// built a new constructor, for the purpose of this exercise, with one argument (double testvalue). One could wrongly believe that giving two values 1.0 would 
// construct a Point object into the constructor found on line 17 in the Point.cpp file. Also, in the if condition, it states: p==1.0; to which two inputs is this referring to?
//
//What is happening, and how is it possible it compiles?
//
//The 1.0 in the if statement is being converted into a Point object. We do not want that, but rather create the Point object and then checking for the condition.

	Point p(1.0, 1.0);
	if (p== (Point) 1.0) 
	{
		std::cout << "Equal!" << std::endl;
	}
	else 
	{
		std::cout << "Not equal" << std::endl;
	}
	
	return 0;
}