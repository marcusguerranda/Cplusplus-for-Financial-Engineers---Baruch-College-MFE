// TestPoint.hpp 
// Purposes: Create a Line class and give it a certain functionality using const arguments, const functions, and pass objects by reference where applicable.
// Modification dates: 11/17/2022 
//
// REMARKS AND OBSERVATIONS: 



#include "Point.hpp" //Header file that contains declarations for Point header file
#include "Line.hpp" //Header file that contains declarations for Line header file
#include <iostream>


int main()
{
	double newxval = 0, newyval = 0;	//Initializing two variables, which will store inputs from user
	
//POINT 1:

	std::cout << "User, please provide x- and y-coordinates in a subsequent manner:" << std::endl << "x y" << std::endl; //Asking users for x- and y-coordinates
	if (!(std::cin >> newxval >> newyval))
	{
		std::cout << "User, we have worked on so many exercises. Provide adequate point coordinate inputs, please." << std::endl; //Catch any wrong inputs
	}

	Point point1;		// Creating instance 1 of Point class, with the given inputs from the user
	point1.X(newxval);	// Setting the X and Y coordinates given by the user.
	point1.Y(newyval);

//POINT 2:
	std::cout << "User, please provide x- and y-coordinates in a subsequent manner:" << std::endl << "x y" << std::endl; //Ask for second point from user
	if (!(std::cin >> newxval >> newyval))
	{
		std::cout << "User, we have worked on so many exercises. Provide adequate point coordinate inputs, please." << std::endl; //Catch any wrong inputs
	}

	Point point2; 		// Creating instance 1 of Point class, with the given inputs from the user
	point2.X(newxval);	// Setting the X and Y coordinates given by the user.
	point2.Y(newyval);

//DESCRIPTION OF THE LINE

	Line line1(point1, point2); //Initializing first line
	std::cout << line1.ToString() << std::endl;	//Information about line 1

//LENGTH OF LINE 1

	std::cout << "Line is of length: " << line1.Length() << std::endl;

	return 0;
}

