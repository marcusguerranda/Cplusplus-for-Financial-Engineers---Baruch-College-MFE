// main.cpp 
// Purposes: Demonstrating simple inheritance, using colon syntax
// Modification dates: 11/27/2022 


#include "Array.hpp"					//Including header file for Array class
#include "Point.hpp"					//Including header file for Point class			
#include "Line.hpp"						//Including header file for Line class
#include "Circle.hpp"					//Including header file for Circle class


using AndrewGuerrand::CAD::Point;		//Using namespace AndrewGuerrand:CAD and specific classes we are going to use
using AndrewGuerrand::CAD::Line;
using AndrewGuerrand::CAD::Shape;
using AndrewGuerrand::CAD::Circle;

int main()
{

	Shape s; 													// Create shape.
	Point p(10, 20); 											// Create point.
	Line l(Point(1,2), Point(3, 4)); 							// Create line.
	
	std::cout << s.ToString() << std::endl; 					// Print shape.
	std::cout << p.ToString() << std::endl; 					// Print point.
	std::cout << l.ToString() << std::endl; 					// Print line
	
	std::cout << "Shape ID: " << s.ID() << std::endl; 			// ID of the shape. (does not work)
	std::cout << "Point ID: "<< p.ID() << std::endl;			// ID of the point. Does this work? 
	std::cout << "Line ID: " << l.ID() << std::endl; 			// ID of the line. Does this work?

//Both work (YES) -- this is because of inheritance of base class functions to derived objects, and here Shape() becoming the public interface
//of the derived classes Point() and Line(). 
	
	Shape* sp; 													// Create pointer to a shape variable.
	sp=&p;								 						// Point in a shape variable. Possible?
	std::cout << sp->ToString() << std::endl; 					// What is printed?  --> ID: 18467
	
//YES, it is possible to create pointers to shape variables, or shape variables pointing to derived objects. 
//This is simply explained by the fact that we use composition (IS-A relationship).
//I also notice that here, ToString() is called into the Shape() abstract class (ID: 18467). This is because ToString() is not virtual in Shape.hpp.

//Running several times the same program, I get the same IDs, and most notably the same ID for that of sp->ToString().
//I suspect this is because for a given seed, rand() will always return the same sequence.
	
	// Create and copy Point p to new point.
	Point p2;
	p2=p;
	std::cout << p2 << ", "<< p2.ID() << std::endl; 				// Is the ID copied if you do not call
																	// the base class assignment in point?
// NO - ID is not copied if one does not call the base class assignment in point.
//If the base class assignment operator is not called, only derived data members are copied; the compiler will not automatically call the base
//class assignment operator to copy base class data members.


//ADDING CODE TO TEST INHERITANCE


//POINTS
	Point point3(23.1, 12.3);										//Creating and initializing point 3
	Point point4(303.2, 10.2);										//Creating and initializing point 4

	std::cout<< "Point 3:" <<point3.ToString() << "ID is:" << point3.ID() << std::endl;		//Printing out info about point 3 and about id 
	std::cout<< "Point 4:" <<point4.ToString() << "ID is:" <<point4.ID() << std::endl;		//Printing out info about point 4 and about id 

	point4= point3;
	std::cout<< "Point 4 made equal to point 3, by using assignment operator in Point class" << std::endl;
	std::cout<< "Point 3:" <<point3.ToString() << "ID is:" <<point3.ID() << std::endl;		//Printing out info about point 3 and about id 
	std::cout<< "New Point 4" <<point4.ToString() << "ID is:" <<point4.ID() << std::endl;	//Printing out info about new point 4 and about id 

//LINES
	Line line2(point4, point3);																//Creating and initializing line 2
											
	std::cout<< "Line l:" <<l.ToString() << "ID is:" << l.ID() << std::endl;				//Printing out info about line l created above, and about id 
	std::cout<< "Line 2:" <<line2.ToString() << "ID is:" <<line2.ID() << std::endl;			//Printing out info about line 2 and about id 

	line2= l;
	std::cout<< "Line2 made equal to line l, by using assignment operator in Line class" << std::endl;
	std::cout<< "Line l:" <<l.ToString() << "ID is:" << l.ID() << std::endl;				//Printing out info about line l created above, and about id 
	std::cout<< "Line 2:" <<line2.ToString() << "ID is:" <<line2.ID() << std::endl;			//Printing out info about new line 2 and about id 
	
//CIRCLE

	Circle circle1(p2, 5.0);																//Creating circle 2 with point p2 initially given and radius 5
	Circle circle2(point4, 5.0);																//Creating circle 2 with point 4 and radius 5
	std::cout<< "Circle l:" <<circle1.ToString() << "ID is:" << circle1.ID() << std::endl;	//Printing out info about line l created above, and about id 
	std::cout<< "Circle 2:" <<circle2.ToString() << "ID is:" <<circle2.ID() << std::endl;	//Printing out info about line 2 and about id 

	circle1= circle2;
	std::cout<< "Circle 1 made equal to Circle 2, by using assignment operator in Circle class" << std::endl;
	std::cout<< "Circle l:" <<circle1.ToString() << "ID is:" << circle1.ID() << std::endl;	//Printing out info about line l created above, and about id 
	std::cout<< "Circle 2:" <<circle2.ToString() << "ID is:" <<circle2.ID() << std::endl;	//Printing out info about new line 2 and about id 
	

//If the derived object is created, the data members of the base part will be created first. 
//The base class constructor will initialize those members. After the base data members are created and initialized the data members of the derived object are created 
//after which the object exists. At object destruction the destructor of the object to be destroyed is called. 
//If the object is a derived object its destructor gets called first after which the destructor for the base part is called.

	return 0;			
}
