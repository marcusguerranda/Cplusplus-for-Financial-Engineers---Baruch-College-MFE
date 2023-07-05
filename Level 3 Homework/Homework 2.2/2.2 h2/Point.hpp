// Point.hpp 
// Purpose: Header file of points defined in 2 dimensions
// Modification dates: 11/16/2022 


#ifndef Point_hpp
#define Point_hpp

#include <sstream> 

class Point	//Set a new class
{
private:

//DATA MEMBERS
    
    double m_x;	//x-coordinate
	double m_y;	//y-coordinate

public:		

//CONSTRUCTOR AND DESTRUCTOR	
    
    Point();    //Default constructor
	~Point();   //Destructor

//SELECTORS
	
    double GetX(); //Functions to get the value of X and Y
    double GetY();	

//MODIFIERS
	
    void SetX(double newxval);  //Functions to set (new) values for X and Y 
    void SetY(double newyval);	
    
    std::string ToString();     //Function ToString() to return a string description of the point.
    
    double DistanceOrigin();    //Declaring a function that calculates the distance betwen a point and its origin
    double Distance(Point p);   //Declaring a function that calculates the distance betwen two points
};

#endif