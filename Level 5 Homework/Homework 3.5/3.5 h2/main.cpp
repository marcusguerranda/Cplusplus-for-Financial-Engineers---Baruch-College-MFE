// main.cpp 
// Purposes: Printing out IDs for lines and points by including ToString() method of base class into ToString() methods in derived classes.
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
	
	std::cout << "Shape ID: " << s.ID() << std::endl; 			// ID of the shape.  Shape ID: 41
	std::cout << "Point ID: "<< p.ID() << std::endl;			// ID of the point.  Point ID: 18467
	std::cout << "Line ID: " << l.ID() << std::endl; 			// ID of the line.   Line ID: 19169

	std::cout<< "Shape ID: "<< s.ID() << std::endl; 			// ID of the shape. Yes: Shape ID: 41
	std::cout<< "Point ID: "<< p.ID() << std::endl; 			// ID of the point. Does this work? Yes: ID:18467 Point(10,20)
	std::cout<< "Line ID: "<< l.ID() << std::endl; 				// ID of the line. Does this work? Line ID: 19169

	
	Shape* sp; 													// Create pointer to a shape variable.
	sp=&p;								 						// Point in a shape variable. 
	std::cout << sp->ToString() << std::endl; 					//Prints object ID and what that object is: ID:18467 Point(10,20)
	std::cout << sp->ID() << std::endl; 						//Prints id of point object: 18467
	std::cout << p.ToString() << std::endl;						//Prints object ID and what that object is: ID:18467 Point(10,20)
	std::cout << p.ID() << std::endl;							//Prints id of point object: 18467

	return 0;			
}



/*
CONCLUSION: YES, the ID is printed when printing a point or line.

	Output BEFORE including base class ToString() method in ToString() methods of derived classes Point, Line, Circle:

ID:41
Point(10,20) 
Line starting with: Point(1,2) and ending with: Point(3,4) 

Shape ID: 41
Point ID: 18467
Line ID: 19169

Shape ID: 41
Point ID: 18467
Line ID: 19169

Point(10,20) 
18467
Point(10,20) 
18467

	
	
	Output AFTER including base class ToString() method in ToString() methods of derived classes Point, Line, Circle:

ID:41
ID:18467Point(10,20)
ID:19169Line starting with: ID:26500Point(1,2) and ending with: ID:6334Point(3,4)

Shape ID: 41
Point ID: 18467
Line ID: 19169
Shape ID: 41
Point ID: 18467
Line ID: 19169
ID:18467Point(10,20)
18467
ID:18467Point(10,20)
18467

ID:41
ID:18467 Point(10,20)
ID:19169 Line starting with: ID:26500 Point(1,2) and ending with: ID:6334 Point(3,4)

Shape ID: 41
Point ID: 18467
Line ID: 19169
Shape ID: 41
Point ID: 18467
Line ID: 19169
ID:18467 Point(10,20)
18467
ID:18467 Point(10,20)
18467

*/