// main.cpp - Exercise 3.5 h5
// Purposes:  Implementation of pure member virtual function (PVMF) Draw() in Shape class, and derived classes Line, Point, Circle.
//			  Drawing these supposed figures and seeing the effects of having a PVMF
//            Use of Template Method Pattern 
// Modification dates: 11/28/2022 


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
    Point point1(3.2, 8.4);         //Creation of point 1 with overloaded constructor
    Point point2;                   //Creation of point 2 with default constructor
    Line line1(point1, point2);     //Creation of line 1 ith points 1 and 2 in overloaded constructor

    point1.Print();                 //Printing information about point 1, point 2, and line 1 with the Template Method Pattern
    point2.Print();
    line1.Print();

    return 0;
}

//CONCLUSION:  Yes it works perfectly fine. This is because of the nature of the template method pattern, whereby the defining of Print() method
//             in the base class, and most especially calling polymorphic function ToString(), which was made virtual, prints out the appropriate 
//             description of the object at stake.


