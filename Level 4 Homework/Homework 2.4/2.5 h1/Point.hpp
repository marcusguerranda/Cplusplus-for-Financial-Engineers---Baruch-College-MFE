// Point.hpp 
// Purpose: Header file of points defined in 2 dimensions
// Modification dates: 11/2/2022 


#ifndef Point_hpp
#define Point_hpp

#include <iostream>
#include <sstream>      //C++ stream buffering 


class Point	//Set a new class
{
private:

//DATA MEMBERS
    
    double m_x;	                                //x-coordinate
	double m_y;	                                //y-coordinate

public:		

//CONSTRUCTORS AND DESTRUCTOR	
    
    Point();                                                    //Default constructor
    Point(double newyval, double newxval);                      //Overloaded constructor, instead of using SetX and SetY functions
    explicit Point(double tesvalue);                            //Testing constructor for exercise 2.4.3
    Point (const Point &p);                                     //Copy constructor
    Point &operator = (const Point &p);                         //Assignment operator
	~Point();                                                   //Destructor

//SELECTORS
	
    double X() const;                                                       //Functions to get the value of X and Y, making the getter function a const function
    double Y() const;	

//MODIFIERS
	
    void X(double newxval);                                                 //Functions to set (new) values for X and Y 
    void Y(double newyval);	

    std::string ToString() const;	                                        //Function ToString() to return a string description of the point.
    friend  std::ostream& operator << (std::ostream &os, const Point &p);   //Ostream operator overloading, to replace ToString()

    double Distance() const;                                                //Declaring a function that calculates the distance betwen a point and its origin
    double Distance(const Point &p) const;                                  //Declaring a function that calculates the distance betwen two points, using call by reference

//OPERATOR OVERLOADING

    Point operator - () const;                  //Negate the coordinates
    Point operator * (double factor) const;     //Scale the coordinates
    Point operator + (const Point &p) const;    //Add coordinates
    bool operator == (const Point &p) const;    //Equally compare operator
    Point &operator *= (double factor);         //Scale the coordinates and assignment    
}; 

#endif