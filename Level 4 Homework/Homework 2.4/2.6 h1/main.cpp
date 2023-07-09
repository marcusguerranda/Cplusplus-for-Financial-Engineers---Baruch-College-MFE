// main.cpp 
// Purposes: Dynamically creating objects, using pointers, arrays of objects, and arrays of pointers. Also creating namespaces CAD, Containers, and AndrewGuerrand
// Modification dates: 11/23/2022 


#include "Array.hpp"			//Including header file for Array class
#include "Point.hpp"			//Including header file for Point class			
#include "Line.hpp"				//Including header file for Line class
#include "Circle.hpp"			//Including header file for Circle class
#include <iostream>

/*Full class name including namespace for the Point used in the Array class. Note that 
you can use only the CAD part of the namespace without the YourName part because 
the Point is also in the YourName namespace.
• In the main program, the full namespace for Point class.
• In the main program, using declaration for using a single class (Line).
• In the main program, using declaration for a complete namespace (Containers).
• In the main program, using the Circle class by creating a shorter alias for 
the YourName::CAD namespace */

int main()
{

//FULL NAMESPACE FOR POINT CLASS

	AndrewGuerrand::CAD::Point point1(3.0);			//Creating first point with explicit constructor
	AndrewGuerrand::CAD::Point point2(3.4, 9.1);	//Creating second point with overloaded constructor with two arguments
	
	std::cout << "Distance from point 1 to point 2 is: " << point1.AndrewGuerrand::CAD::Point:: Distance(point2) << std::endl;	//Calculating distance from point 1 to point2
	std::cout << "Distance from point 2 to origin is: " << point1.AndrewGuerrand::CAD::Point:: Distance() << std::endl;
	
//USING DECLARATION FOR LINE CLASS

	using AndrewGuerrand::CAD::Line;

	Line line1(point1, point2);										//Initializing first line 
	std::cout << line1 << std::endl; 								//Using << operator overloading, as specified in Line.cpp line 87

//USING DECLARATION FOR COMPLETE NAMESPACE FOR CONTAINERS

	using namespace AndrewGuerrand::Containers;						//Accessing anything related to arrays here
	Array array1(2);
	array1.SetElement(point1,0);									//Setting first element of array 1 to point 1
	array1.SetElement(point2,1);									//Setting second element of array 1 to point 2

	std::cout << "Array 1, of size " << array1.Size() << " has for second element, for example: " << array1.GetElement(1) << std::endl; //Getting size and second element in/of array 1

//USING CIRCLE CLASS BY CREATING SHORTER ALIAS FOR ANDREWGUERRAND::CAD NAMESPACE

	namespace AGC = AndrewGuerrand::CAD; 							//Created alias
	double radius = 3.4;											//Creating random radius for the circle created below
	AGC::Circle circle1(point1, radius);							//Creating circle 1 instance from Circle class using alias
	std::cout << "Circle 1 created!" << std::endl;					
	std::cout << circle1 << std::endl;								//Using << operator overloading to display simple information about the circle

	return 0;
}
