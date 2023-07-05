// TestPoint.hpp 
// Purpose: Main source file creating a program for the Point class, initializing point coordinates, and performing calculations on these class instances.
// Modification dates: 11/17/2022 
//
// REMARKS AND OBSERVATIONS: 
//
//This time around, as we had seen in the previous exercise that a copy constructor was called during the Distance(Point p) calculation,
// we use a const reference so as to not make a copy of point 2, but rather a direct reference, with a const so as to not modify its value during the process.
// HERE, the number of constructor and destructor calls are the same; YET, a copy constructor call is not made, given the call by reference.


#include "Point.hpp" //Header file that contains declarations
#include <iostream>


int main()
{
	double newxval = 0, newyval = 0; //Initializing two variables, which will store inputs from user
	
//POINT 1:

	std::cout << "User, please provide x- and y-coordinates in a subsequent manner:" << std::endl << "x y" << std::endl; //Asking users for x- and y-coordinates
	if (!(std::cin >> newxval >> newyval))
	{
		std::cout << "User, we have worked on so many exercises. Provide adequate point coordinate inputs, please." << std::endl; //Catch any wrong inputs
	}

	Point point1; 			// Creating instance 1 of Point class, with the given inputs from the user
	point1.SetX(newxval);	// Setting the X and Y coordinates given by the user.
	point1.SetY(newyval);

//POINT 2:
	std::cout << "User, please provide x- and y-coordinates in a subsequent manner:" << std::endl << "x y" << std::endl; //Ask for second point from user
	if (!(std::cin >> newxval >> newyval))
	{
		std::cout << "User, we have worked on so many exercises. Provide adequate point coordinate inputs, please." << std::endl; //Catch any wrong inputs
	}

	Point point2; 			// Creating instance 2 of Point class, with the given inputs from the user
	point2.SetX(newxval);	// Setting the X and Y coordinates given by the user.
	point2.SetY(newyval);


//PRINTING DISTANCE FROM ORIGIN:

	std::cout << "The distance from the origin for point 1 is: " << point1.DistanceOrigin() << std::endl; //For point 1
	std::cout << "The distance from the origin for point 2 is: " << point2.DistanceOrigin() << std::endl; //For point 2


//PRINTING DISTANCE BETWEEN TWO POINTS:

	std::cout << "The distance between point 1 and point 2 is: " << point1.Distance(point2) << std::endl; 


//CREATING POINT WITHOUT ANY VALUES, AS WELL AS USING OVERLOADED CONSTRUCTOR

	Point point3; 			//It will output text, as defined in source file "Point.cpp"
	Point point4(20,39);	//Creation of point 4 using overloaded constructor
	
	return 0;
}

