// main.cpp  - Exercise 3.5 h4
// Purposes:  Implementation of pure member virtual function (PVMF) Draw() in Shape class, and derived classes Line, Point, Circle.
//			      Drawing these supposed figures and seeing the effects of having a PVMF
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
    Shape* shapes[9];										//Creation of 8 Shape* pointers to derived classes Point, Line, and Circle
															          //Same order of constructors as in .hpp files for Point, Line, and Circle
    shapes[0] = new Point();                                // Default constructor for point
    shapes[1] = new Point(3.0, 4.0);                        // Constructor with two given coordinates for a point
    shapes[2] = new Point(Point(2.3, 4.3));                 // Copy constructor with Point(2.3, 4.3) using overloaded constructor for point
   
    shapes[3] = new Line;                                   // Default constructor for line
    shapes[4] = new Line(Point(1.0, 2.5), Point(3.4, 5.2)); // Overloaded constructor taking two points as argument, using overloaded point constructor
    shapes[5] = new Line(Line());                           // Copy constructor for a temp line (used default line here)
   
    shapes[6] = new Circle();                               // Default constructor for circle
    shapes[7] = new Circle(Point(), 5.0);                   // Overloaded constructor taking a defaul point, and inputted radius
    shapes[8] = new Circle(Circle());                       // Copy constructor of a temp circle (used default circle, as above for shape[5])
    

    for (int i = 0; i != 9; i++) shapes[i]->Draw();  	      // Calling Draw() method defined in derived classes
		for (int i = 0; i != 9; i++) delete shapes[i];  	      // Deleting temporary instances in derived clases

    return 0;
}

/*  
CONCLUSIONS:

What implementation did you give the Draw() function in Shape?

Prior to making Draw() a PVMF, I had just defined Draw() in Shape.hpp as:  void Draw() const. (in reality, I knew to make it = 0, as show in lecture notes)
    
Draw() has an empty implementation, but we use = 0 to give it no implementatio whatsoever by making it a PVMF.
    
In turn, as seen in class, whence a class has at least one pure virtual member function, then that class is an abstract base class.
Abstract base classes cannot have instances, and therefore it is not possible to draw a shape.

*/


