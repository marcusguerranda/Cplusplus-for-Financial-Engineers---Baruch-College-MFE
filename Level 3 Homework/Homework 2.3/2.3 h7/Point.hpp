// Point.hpp 
// Purpose: Header file of points defined in 2 dimensions
// Modification dates: 11/17/2022 

#ifndef Point_hpp
#define Point_hpp

#include <sstream> //C++ stream buffering 
#include <iostream> //C++ I/O

class Point	//Set a new class
{
private:

//DATA MEMBERS
    
    double m_x;	                                //x-coordinate
	double m_y;	                                //y-coordinate

public:		

//CONSTRUCTORS AND DESTRUCTOR	
    
    Point();                                    //Default constructor
    Point(double newyval, double newxval);      //Overloaded constructor, instead of using SetX and SetY functions
    Point(const Point &p);                      //Copy constructor
	~Point();                                   //Destructor

//SELECTORS
	
    double X() const;                           //Functions to get the value of X and Y, making the getter function a const function
    double Y() const;

//MODIFIERS
	
    void X(double newxval) {m_x = newxval;}     //Functions to set (new) values for X and Y 
    void Y(double newyval) {m_y = newyval;}	
    
    std::string ToString() const;	            //Function ToString() to return a string description of the point.
    
    double Distance() const;                    // Declaring a function that calculates the distance betwen a point and its origin
    double Distance(const Point &p) const;      // Declaring a function that calculates the distance betwen two points, using call by reference
};

//SELECTORS

    inline double Point::X() const {return m_x;}    //Normal inline function for getter functions of x and y coordinates
    inline double Point::Y() const {return m_y;}	
#endif