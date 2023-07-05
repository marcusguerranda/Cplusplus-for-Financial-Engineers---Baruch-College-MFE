// TestPoint.hpp 
// Purpose: Main source file creating a program for the Point class, initializing point coordinates, and printing these. 
// Modification dates: 11/16/2022 


#include "Point.hpp" //Header file that contains declarations
#include <iostream>

int main()
{
	double newxval = 0, newyval = 0; //Initializing two variables, which will store inputs from user

	std::cout << "User, please provide x- and y-coordinates in a subsequent manner:" << std::endl << "x y" << std::endl; //Asking users for x- and y-coordinates
	
	if (!(std::cin >> newxval >> newyval))
	{
		std::cout << "User, we have worked on so many exercises. Provide adequate point coordinate inputs, please." << std::endl; //Catch any wrong inputs
	}

	Point point1; // Creating instance of Point class, with the given inputs from the user
				
	point1.SetX(newxval); // Setting the coordinates given by the user.
	point1.SetY(newyval);
					
	std::cout << point1.ToString() << std::endl; // Printing description about point
	std::cout << point1.GetX() << " is the x-coordinate of the given point." << std::endl; 
	std::cout << point1.GetY() << " is the y-coordinate of the given point." << std::endl;

	return 0;
}