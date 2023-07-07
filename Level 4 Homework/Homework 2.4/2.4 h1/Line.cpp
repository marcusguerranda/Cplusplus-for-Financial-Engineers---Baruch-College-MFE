// Line.cpp 
// Purpose: Source file for line file Line.hpp
// Modification dates: 11/21/2022 


#include "Line.hpp"     //Header file that contains declarations about lines
#include "Point.hpp"    //Header file that contains declarations about points
#include <sstream>      //C++ stream buffering      
#include <cmath>        //Math functions used in distance calculations
#include <iostream>

Line::Line(): p_starting(0,0), p_ending(0,0)            //Default constructor, and list initialization method as seen further in Lecture 3-04
{
    //OR simply:
    //p_starting = 0;
    //p_ending=0;
}

Line::Line( const Point& starting,  const Point &ending): p_starting(starting), p_ending(ending)  //Constructor with two given points, start and end
{
}

Line::Line(const Line &l): p_starting(l.p_starting), p_ending(l.p_ending)                        //Copy constructor of referenced line
{
}

Line& Line::operator = (const Line &l)                  //Assignment operator
{
    if (this == &l)
    {
        return *this;                                   //Self-assignment as discussed in lecture 2-04
    }
    else
    {
        p_starting = l.p_starting;
        p_ending = l.p_ending;

        return *this;                                   //Current object is returned
    }
}


Line::~Line()                                           //Destructor
{
}

const Point& Line::P1() const          //Getter function that returns the value of the starting point of a line
{
    return p_starting;
}

const Point& Line::P2() const            //Getter function that returns the value of the ending point of a line
{
    return p_ending;
}

void Line::P1(const Point &p)
{
    p_starting = p;                                     //See instance definition line 16 and 17 in "TestPoint.cpp"
}

void Line::P2(const Point &p)
{
    p_ending = p;                                       //See instance definition line 16 and 17 in "TestPoint.cpp"
}

std::string Line::ToString()                            //Function that returns a description of of the line
{
    // Similar to previous exercises, we retrieve x and y coordinates for both starting and ending points with the functions X and Y defined in "Point.cpp"

    std::stringstream ss; 
	ss << "Line starting with: " <<  p_starting.ToString() << "and ending with: " << p_ending.ToString() << std::endl;
	return ss.str(); // String retrieval from string buffer
}

double Line::Length() const                             //See "Point.cpp" in the defining of the Distance function
{
    return  p_starting.Distance(p_ending);
}



