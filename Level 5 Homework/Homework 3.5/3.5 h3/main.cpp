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

	Shape* shapes[3];
	shapes[0]=new Shape;
	shapes[1]=new Point;
	shapes[2]=new Line;
	for (int i=0; i!=3; i++) delete shapes[i];
		return 0;			
}



/*

CONCLUSION: Prior to using virtual destructors, we had seen in class (and this materializes in the output + creation + destruction process) that base class data
			members are first created, and then derived data members are created subsequently. The destruction process is just in reverse order, with first derived data members
			being destroyed, till eventually the data members from the base class are destroyed.
	
Without using virtual destructors, only the data members in the base (Shape) class are called. 

When using virtual destructors, the entire creation and destruction processs is respected (the order, that is) and derived and base class destructors are called.

	Output BEFORE using virtual destructors


							//CREATION PROCESS

Shape DEFAULT constructor.
Shape DEFAULT constructor.
User, a new point in DEFAULT CONSTRUCTOR was created.
Shape DEFAULT constructor.
Shape DEFAULT constructor.
User, a new point in DEFAULT CONSTRUCTOR was created.
Shape DEFAULT constructor.
User, a new point in DEFAULT CONSTRUCTOR was created.
User, a new LINE in DEFAULT CONSTRUCTOR was CREATED.


							//DESTRUCTION PROCESS

Shape DESTRUCTOR used.
Shape DESTRUCTOR used.
Shape DESTRUCTOR used.




	Output AFTER using virtual destructors
							
							//CREATION PROCESS

Shape DEFAULT constructor.
Shape DEFAULT constructor.
User, a new point in DEFAULT CONSTRUCTOR was created.
Shape DEFAULT constructor.
Shape DEFAULT constructor.
User, a new point in DEFAULT CONSTRUCTOR was created.
Shape DEFAULT constructor.
User, a new point in DEFAULT CONSTRUCTOR was created.
User, a new LINE in DEFAULT CONSTRUCTOR was CREATED.


							//DESTRUCTION PROCESS

Shape DESTRUCTOR used.
User, a point was DESTROYED.
Shape DESTRUCTOR used.
User, a line was DESTROYED.
User, a point was DESTROYED.
Shape DESTRUCTOR used.
User, a point was DESTROYED.
Shape DESTRUCTOR used.
Shape DESTRUCTOR used.






*/