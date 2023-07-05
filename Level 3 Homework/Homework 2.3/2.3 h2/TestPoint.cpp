// TestPoint.hpp 
// Purpose: Main source file creating a program for the Point class, initializing point coordinates, and printing these. 
// Modification dates: 11/16/2022 
//
// REMARKS AND OBSERVATIONS: 
//
// There are as many constructor and destructor calls. HOWEVER, when calculating the distance between point 1 and point 2 on line 44, a copy constructor of point 2 
// is made such as to proceed with calculations, and subsequently destroyed. 


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

	Point point1; // Creating instance 1 of Point class, with the given inputs from the user
	point1.SetX(newxval); // Setting the X and Y coordinates given by the user.
	point1.SetY(newyval);

//POINT 2:
	std::cout << "User, please provide x- and y-coordinates in a subsequent manner:" << std::endl << "x y" << std::endl; //Ask for second point from user
	if (!(std::cin >> newxval >> newyval))
	{
		std::cout << "User, we have worked on so many exercises. Provide adequate point coordinate inputs, please." << std::endl; //Catch any wrong inputs
	}

	Point point2; //// Creating instance 1 of Point class, with the given inputs from the user
	point2.SetX(newxval); // Setting the X and Y coordinates given by the user.
	point2.SetY(newyval);

//PRINTING DISTANCE FROM ORIGIN:

	std::cout << "The distance from the origin for point 1 is: " << point1.DistanceOrigin() << std::endl; //For point 1
	std::cout << "The distance from the origin for point 2 is: " << point2.DistanceOrigin() << std::endl; // For point 2

//PRINTING DISTANCE BETWEEN TWO POINTS:

	std::cout << "The distance between point 1 and point 2 is: " << point1.Distance(point2) << std::endl; 

//CREATING POINT WITHOUT ANY VALUES, AS WELL AS USING OVERLOADED CONSTRUCTOR

	Point point3; //It will output text, as defined in source file "Point.cpp"
	Point point4(20,39); //Creation of point 4 using overloaded constructor
	
	return 0;
}

