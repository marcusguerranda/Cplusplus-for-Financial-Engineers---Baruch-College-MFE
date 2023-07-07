// TestPoint.hpp 
// Purposes: Create a Line class and give it a certain functionality using const arguments, const functions, and pass objects by reference where applicable.
//			 We use inline functions to speed up.
// Modification dates: 11/18/2022 

#include "Point.hpp" 	//Header file that contains declarations for Point header file
#include <iostream>

int main()
{
	double newxval = 0, newyval = 0;	//Initializing two variables, which will store inputs from user
	
//POINT 1: Centerpoint

	std::cout << "User, please provide x- and y-coordinates in a subsequent manner:" << std::endl << "x y" << std::endl; //Asking users for x- and y-coordinates
	if (!(std::cin >> newxval >> newyval))
	{
		std::cout << "User, we have worked on so many exercises. Provide adequate point coordinate inputs, please." << std::endl; //Catch any wrong inputs
	}

	Point point1;		// Creating instance 1 of Point class, with the given inputs from the user
	point1.X(newxval);	// Setting the X and Y coordinates given by the user.
	point1.Y(newyval);

//TESTING GETTER FUNCTIONS

	std::cout << "X value for point 1 is: " << point1.X() << std::endl; //Getter function X()
	std::cout << "Y value for point 1 is: " << point1.Y() << std::endl; //Getter function Y()

//TESTING SETTER FUNCTIONS
	
	std::cout << "We are now changing values of x- and y- coordinates for point 1." << std::endl;

	point1.X(3.0);	//Setter function, defining x-coordinate to 3.0 now
	point1.Y(5.4);	//Setter function, definingy y-coordinate to 5.4 now

	std::cout << "X value for point 1 NOW is: " << point1.X() << std::endl;
	std::cout << "Y value for point 1 NOW is: " << point1.Y() << std::endl; 

	return 0;
}