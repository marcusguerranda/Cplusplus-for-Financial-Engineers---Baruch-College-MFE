// Line.cpp 
// Purpose: Source file for line file Line.hpp
// Modification dates: 11/17/2022 


#include "Line.hpp"     //Header file that contains declarations about lines
#include "Point.hpp"    //Header file that contains declarations about points
#include <sstream>      //C++ stream buffering 
#include <iostream>     
#include <cmath>        //Math functions used in distance calculations

Line::Line(): p_starting(0,0), p_ending(0,0)            //Default constructor
{
}

Line::Line(const Point& starting, const Point &ending)  //Constructor with two given points, start and end
{
    p_starting = starting; 
    p_ending = ending;

}

Line::Line(const Line &l)                               //Copy constructor of referenced line
{
    p_starting = l.p_starting;
    p_ending = l.p_ending;
}

Line::~Line()                                           //Destructor
{
}

Point const &Line::P1() const                           //Getter function that returns the value of the starting point of a line
{
    return p_starting;
}

Point const &Line::P2() const                           //Getter function that returns the value of the ending point of a line
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
	return ss.str();                                    // String retrieval from string buffer
}

double Line::Length() const                             //See "Point.cpp" in the defining of the Distance function
{
    return  p_starting.Distance(p_ending);
}



