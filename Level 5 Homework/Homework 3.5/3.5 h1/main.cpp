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
	
	std::cout << "Shape ID: " << s.ID() << std::endl; 			// ID of the shape.
	std::cout << "Point ID: "<< p.ID() << std::endl;			// ID of the point.  
	std::cout << "Line ID: " << l.ID() << std::endl; 			// ID of the line.
	
	Shape* sp; 													// Create pointer to a shape variable.
	sp=&p;								 						// Point in a shape variable. 
	std::cout << sp->ToString() << std::endl; 					//Prints out the pointer object at stake here: Point(10,20)
	std::cout << p.ToString() << std::endl;						//Prints out the pointer object at stake here: Point(10,20)
	std::cout << p.ID() << std::endl;							//Prints out m_id of the point object at stake here: 18467

//Given that we declared ToString() as virtual in the Shape abstract class, the ToString() in the Point class is called, rather than the 
//ToString() in Shape class. Shape* now knows which function to call.
//I uncommented out std::cout expressions in ToString() functions to figure out what was precisely happening, and thus to come about this conclusion, as well as just looking 
//at the printed output for the calls above.

	return 0;			
}
