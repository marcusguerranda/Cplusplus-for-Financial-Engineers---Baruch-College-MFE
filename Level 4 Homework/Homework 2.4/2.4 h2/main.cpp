// main.cpp 
// Purposes: Testing different operator overloadings as seen in Level 4 lectures (assignment operator, scaling, adding, etc.) and seeing how this affects instances.
// Modification dates: 11/21/2022 


#include "Point.hpp" 	//Header file that contains declarations for Point header file
#include "Line.hpp"		//Header file that contains declarations for Line header file
#include "Circle.hpp" 	//Header file that contains declarations for Circle header file
#include <iostream>

int main()
{
	double newxval = 0, newyval = 0, radius = 0;	//Initializing two variables, which will store inputs from user
	
//POINT 1:

	std::cout << "User, please provide x- and y-coordinates in a subsequent manner:" << std::endl << "x y" << std::endl; 			//Asking users for x- and y-coordinates
	if (!(std::cin >> newxval >> newyval))
	{
		std::cout << "User, we have worked on so many exercises. Provide adequate point coordinate inputs, please." << std::endl; 	//Catch any wrong inputs
	}

	Point point1;									//Creating instance 1 of Point class, with the given inputs from the user
	point1.X(newxval);								//Setting the X and Y coordinates given by the user.
	point1.Y(newyval);
	std::cout << point1.ToString() << std::endl;	//Printing description about point 1

	std::cout << "Creation of Point 2 by using the coordinates of Point 1 (using assignment operator)." << std::endl;
	Point point2 = point1;							//Using assignment operator, and avoiding copy of variable by using *this, as described in header file "Point.hpp"

	point1 = - point1  ;							//Negating coordinates of point 1 using operator - (); point 1 is now a const.
	std::cout << point1.ToString() << "is now the new value of point 1 with negative coordinates. " << std::endl;	

	point1 *= 3.0;									//Scaling coordinates by a factor of 3
	std::cout << point1.ToString() << "is now the new value of point 1 with negative and scaled coordinates. " << std::endl;	

	Point point3 = point1 + point2;					//Adding coordinates of point 1 and point 2 to a new instance, being point 3
	std::cout << "Creation of point 3, by adding points 1 and 2: " << point3.ToString() << std::endl;

	std::cout << "Let's check whether points 1 and 3 are equal: " << std::endl;							//Checking equality operator 
	std::cout << "\n";
	std::cout << ((point1 == point3) ? "They are equal." : "They are not equal.") << std::endl;
	std::cout << "\n";

	Point point4 = point3*(4.0);																		//Scaling point 3 by a factor of 4, and assigning value to new instance point4.
	std::cout << "We have scaled point 3 by a factor of 4, which gives the value of: " << point4.ToString() << std::endl;
	std::cout << "\n";

//TESTING LINE CLASS WITH ASSIGNMENT OPERATOR

	Line l1(point1, point2);									//Creating line 1 with values of point 1 and point 2
	Line l2(point3, point4);									//Creating line 2 with values of point 3 and point 4

	std::cout << "Line 1 -> " << l1.ToString() << std::endl;	//Printing description about line 1
	std::cout << "Line 2 -> " << l2.ToString() << std::endl;	//Printing description about line 2

	std::cout << "Making Line 2 equal to Line 1, by using assignment operator." << std::endl;
	std::cout << "\n";
	l1 = l2;													//Using assignment operator
	std::cout << "Line 1 -> " << l1.ToString() << std::endl;	//Printing description about line 1 again
	std::cout << "Line 2 -> " << l2.ToString() << std::endl;	//Printing description about line 2 again


//TESTING CIRCLE CLASS WITH ASSIGNMENT OPERATOR

	Point point5 (0, 0);
	std::cout << "User, please give a radius value for your circle in float form: " << std::endl;
	if (!(std::cin >> radius))
	{
		std::cout << "User, we have worked on so many exercises. Provide an adequate radius value, please." << std::endl; //Catch any wrong inputs
	}

	Circle c1 = Circle(point5, radius);								//Creation of a circle 1
	Circle c2 = Circle (point1, radius);							//Creation of a circle 2

	std::cout << "CIRCLE 1: " << c1.ToString() << std::endl;
	std::cout << "CIRCLE 2: " << c2.ToString() << std::endl;	

	std::cout << "Using assignment operator to assign values of Circle to Circle 2. Below will be printed info about these using << operator." << std::endl;
	std::cout << "\n";
	
	c2 = c1;

	std::cout << "CIRCLE 2 (using ToString()): " << c2.ToString() << std::endl;					//Assignment operator; the values of circle 2 should now have changed

	std::cout << "CIRCLE 1 (using << operator): " << c1 << std::endl;							//Printing out inforation
	std:: cout << "CIRCLE 2 (using << operator): " << c2;

	return 0;
}