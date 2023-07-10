// main.cpp 
// Purposes: Demonstrating simple inheritance, using colon syntax
// Modification dates: 11/27/2022 


#include "Array.hpp"			//Including header file for Array class
#include "Point.hpp"			//Including header file for Point class			
#include "Line.hpp"				//Including header file for Line class
#include "Circle.hpp"			//Including header file for Circle class
#include <iostream>


namespace AG = AndrewGuerrand;

int main()
{
	/*
	All comments about particular deccisions are to be found below, as well as the results. I have also commented out previous initialization in constructors/destructor/copy 
	assignment/assignment operator, to see what I had coded before, and what is to be found currently with the colon syntax.
	Three runs were asked to be performed: 1) the first with no colon syntax used, 2) the second with colon syntax used in Line.cpp exclusively, and 3) the third with both
	the colon syntax used in Point.cpp, Line.cpp, and Circle.cpp.
	*/
	namespace AG = AndrewGuerrand;
	AG::CAD::Point point1(0.3, 0.6);	//Creating and initializing first point
	AG::CAD::Point point2(1.7, 2.3);	//Creating and initializing second point

	std::cout << point1 << point2 << std::endl; 	//Describing first two points with << operator 

	using AG::CAD::Line;							//Namespace declaration to use contents in Line class

	Line line1(point1, point2);						//First line created with points 1 and 2 as starting and ending points
	std::cout << line1;								//Using << operator to put out description of line 1, rather than use ToString()

	Line line2 = line1;								//Using assignment operator; deep copy assignment

	using AG::CAD::Circle;							//Namespace declaration to use contents in Circle class
	Circle circle1(point1, 5.0);					//Creating circle 1, with center point point 1 and radius 5
	Circle circle2(point2, 7.0);					//Creating circle 2, with center point a point newly created and radius 5

	std::cout << circle1 << std::endl;				//Using << operator to print description about circle 1
	std::cout << circle2 << std::endl;				//Using << operator to print description about circle 2

	circle2 = circle1;								//Using assignment operator
	std::cout << circle2 << std::endl;				//Printing new description about circle 2

	return 0;			
}

/* 
1. RUN WITH NO INITIALIZATION LISTS WITH COLON SYNTAX, IN NEITHER POINT NOR LINE
2. RUN WITH INITIALIZATION LIST IN LINE.CPP, BUT NOT IN POINT.CPP
3. RUN WITH INITIALIZATION LIST IN POINT.CPP, LINE.CPP, AND CIRCLE.CPP


Observations, as per the outputs found below: whence using the colon syntax, we get less constructor calls as it is a more efficient way to initialize when using multiple objects.
In other words, the number of times the member objects are constructed decreases when using the colon syntax.

In turn, one needs to be aware, and at the expense of quite alot of time figuring this out, that working with primitives will go against the whole purpose of this exercise: which is
to gauge the impact of using the colon syntax in the initialization process when dealing with NON-PRIMITIVE OBJECTS. Hence, there is no benefit using the colon syntax for Point, but
only Circle and Line, given they call non-primitive objects themselves (points).
*/




/*   

	1.     RUN WITH NO INITIALIZATION LISTS WITH COLON SYNTAX, IN NEITHER POINT NOR LINE:  (text being put in constructors, destructor, copy constructor, and assignment operator)


User, a new point in OVERLOADED CONSTRUCTOR (two arguments) was created.
User, a new point in OVERLOADED CONSTRUCTOR (two arguments) was created.
Point(0.3,0.6) Point(1.7,2.3)
User, a new point in DEFAULT CONSTRUCTOR was created.
User, a new point in DEFAULT CONSTRUCTOR was created.
ASSIGNMENT OPERATOR USED IN POINT.CPP
ASSIGNMENT OPERATOR USED IN POINT.CPP
User, a new line in OVERLOADED CONSTRUCTOR was CREATED.
Line starting with: Point(0.3,0.6) and ending with: Point(1.7,2.3)
User, a new point in DEFAULT CONSTRUCTOR was created.
User, a new point in DEFAULT CONSTRUCTOR was created.
ASSIGNMENT OPERATOR USED IN POINT.CPP
ASSIGNMENT OPERATOR USED IN POINT.CPP
User, a new line in COPY CONSTRUCTOR was CREATED.
User, a new point in DEFAULT CONSTRUCTOR was created.
ASSIGNMENT OPERATOR USED IN POINT.CPP
User, a new CIRCLE in OVERLOADED CONSTRUCTOR was CREATED.
User, a new point in DEFAULT CONSTRUCTOR was created.
ASSIGNMENT OPERATOR USED IN POINT.CPP
User, a new CIRCLE in OVERLOADED CONSTRUCTOR was CREATED.
This circle has for center: Point(0.3,0.6) , and for radius: 5
This circle has for center: Point(1.7,2.3) , and for radius: 7
ASSIGNMENT OPERATOR USED IN POINT.CPP
This circle has for center: Point(0.3,0.6) , and for radius: 5
User, a CIRCLE has been DESTROYED.
User, a point was DESTROYED.
User, a CIRCLE has been DESTROYED.
User, a point was DESTROYED.
User, a line was DESTROYED.
User, a point was DESTROYED.
User, a point was DESTROYED.
User, a line was DESTROYED.
User, a point was DESTROYED.
User, a point was DESTROYED.
User, a point was DESTROYED.
User, a point was DESTROYED.



      2.     RUN WITH INITIALIZATION LIST IN LINE.CPP, BUT NOT IN POINT.CPP:    (text being put in constructors, destructor, copy constructor, and assignment operator)

User, a new point in OVERLOADED CONSTRUCTOR (two arguments) was created.
User, a new point in OVERLOADED CONSTRUCTOR (two arguments) was created.
Point(0.3,0.6) Point(1.7,2.3)
User, a point was copied with copy constructor.
User, a point was copied with copy constructor.
User, a new line in OVERLOADED CONSTRUCTOR was CREATED.
Line starting with: Point(0.3,0.6) and ending with: Point(1.7,2.3)      
User, a point was copied with copy constructor.
User, a point was copied with copy constructor.
User, a new line in COPY CONSTRUCTOR was CREATED.
User, a new point in DEFAULT CONSTRUCTOR was created.
ASSIGNMENT OPERATOR USED IN POINT.CPP
User, a new CIRCLE in OVERLOADED CONSTRUCTOR was CREATED.
User, a new point in DEFAULT CONSTRUCTOR was created.
ASSIGNMENT OPERATOR USED IN POINT.CPP
User, a new CIRCLE in OVERLOADED CONSTRUCTOR was CREATED.
This circle has for center: Point(0.3,0.6) , and for radius: 5
This circle has for center: Point(1.7,2.3) , and for radius: 7
ASSIGNMENT OPERATOR USED IN POINT.CPP
This circle has for center: Point(0.3,0.6) , and for radius: 5
User, a CIRCLE has been DESTROYED.
User, a point was DESTROYED.
User, a CIRCLE has been DESTROYED.
User, a point was DESTROYED.
User, a line was DESTROYED.
User, a point was DESTROYED.
User, a point was DESTROYED.
User, a line was DESTROYED.
User, a point was DESTROYED.
User, a point was DESTROYED.
User, a point was DESTROYED.
User, a point was DESTROYED.



      3.     RUN WITH INITIALIZATION LIST IN POINT.CPP, LINE.CPP, AND CIRCLE.CPP:  (text being put in constructors, destructor, copy constructor, and assignment operator)

User, a new point in OVERLOADED CONSTRUCTOR (two arguments) was created.
User, a new point in OVERLOADED CONSTRUCTOR (two arguments) was created.
Point(0.3,0.6) Point(1.7,2.3) 
User, a point was copied with copy constructor.
User, a point was copied with copy constructor.
User, a new line in OVERLOADED CONSTRUCTOR was CREATED.
Line starting with: Point(0.3,0.6) and ending with: Point(1.7,2.3) 
User, a point was copied with copy constructor.
User, a point was copied with copy constructor.
User, a new line in COPY CONSTRUCTOR was CREATED.
User, a point was copied with copy constructor.
User, a new CIRCLE in OVERLOADED CONSTRUCTOR was CREATED.
User, a point was copied with copy constructor.
User, a new CIRCLE in OVERLOADED CONSTRUCTOR was CREATED.
This circle has for center: Point(0.3,0.6) , and for radius: 5
This circle has for center: Point(1.7,2.3) , and for radius: 7
ASSIGNMENT OPERATOR USED IN POINT.CPP
This circle has for center: Point(0.3,0.6) , and for radius: 5
User, a CIRCLE has been DESTROYED.
User, a point was DESTROYED.
User, a CIRCLE has been DESTROYED.
User, a point was DESTROYED.
User, a line was DESTROYED.
User, a point was DESTROYED.
User, a point was DESTROYED.
User, a line was DESTROYED.
User, a point was DESTROYED.
User, a point was DESTROYED.
User, a point was DESTROYED.
User, a point was DESTROYED.


*/