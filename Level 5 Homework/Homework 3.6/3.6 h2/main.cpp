// main.cpp - Exercice 3.6 h2
// Purposes:  Implementation of pure member virtual function (PVMF) Draw() in Shape class, and derived classes Line, Point, Circle.
//			      Drawing these supposed figures and seeing the effects of having a PVMF
//            Use of Template Method Pattern
//            Bounds checking error management with exception handling
//            Use of polymorphic nets to catch errors 
// Modification dates: 11/28/2022 


#include "Array.hpp"					//Including header file for Array class
#include "Point.hpp"					//Including header file for Point class			
#include "Line.hpp"						//Including header file for Line class
#include "Circle.hpp"					//Including header file for Circle class
#include "Shape.hpp"
#include "OutOfBoundsException.hpp" //Including header file for ArrayException class


using AndrewGuerrand::CAD::Point;		//Using namespace AndrewGuerrand and specific base/derived classes in CAD or in Containers
using AndrewGuerrand::CAD::Shape;
using AndrewGuerrand::Containers::OutOfBoundsException;
using AndrewGuerrand::Containers::ArrayException;
using AndrewGuerrand::Containers::Array;


int main()
{   
  //Task: Create an Array object and access an element that does not exist. Run the program --> WHAT HAPPENS?

  Array array1(10);                             //Creating an array of size 10


//SETTING AN ELEMENT OUT OF BOUNDS
  try
  {
    array1.SetElement(Point(12.3, 43.2), 0);      //Setting first element with newly created Point(12.3, 43.2)
    array1[1] = Point();                          //Setting second element as default point with [] operator
    array1.SetElement(Point(0,0), 11);            //Setting an element out of bounds, creating an error that will be caught    
  }
  catch(ArrayException& exception)                //Polymorphic net
  {
    std::cout << exception.GetMessage()  << std::endl;
  }                                               //Catching error with the output -1, which we set in SetElement(), GetElement, and [] operators in Array.hpp
  catch(...)
  {
    std::cout << " User, ERROR message from catch(...) !" << std::endl;
  }

//OUT OF BOUNDS ERROR AGAIN
  try
  {
    std::cout << array1.GetElement(0) << std::endl; //GetElement() to get first object in the array 1      
    std::cout << array1[-3];                        //Will print an error
  }
  catch(ArrayException& exception)                  //Polymorphic net
  {
    std::cout << exception.GetMessage()  << std::endl;
  } 
  catch(...)
  {
    std::cout << " User, ERROR MESSAGE from catch(...) !" << std::endl;
  }

//GETTING ELEMENT OUT OF BOUNDS
  try
  {
    std::cout << array1.GetElement(-5);             //Will not be run through because error was caught on previous line
    std::cout << array1.GetElement(11);
  }
  catch(ArrayException& exception)                  //Polymorphic net
  {
    std::cout << exception.GetMessage()  << std::endl;
  } //Catching error with the output -1, which we set in SetElement(), GetElement, and [] operators in Array.hpp
  catch(...)
  {
    std::cout << " User, ERROR MESSAGE from catch(...) !" << std::endl;
  }

    return 0;
}


