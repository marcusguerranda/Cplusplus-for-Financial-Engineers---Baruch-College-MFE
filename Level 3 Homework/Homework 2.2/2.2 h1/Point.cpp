// Point.cpp 
// Purpose: Source file for header file Point.hpp
// Modification dates: 11/16/2022 


#include "Point.hpp" //Header file that contains declarations
#include <sstream>

//CONSTRUCTOR AND DESTRUCTOR

Point::Point(): m_x(0), m_y(0) // Default constructor, using initialization list method
{
	// m_x = 0;
	// m_y=0;
}

Point::~Point()	// Destructor
{
}

//SELECTORS

double Point::GetX() //GetX function that gets private variable x in Point class, and returns it
{
	return m_x;
}

double Point::GetY() //GetY function that gets private variable y in Point class, and returns it
{
	return m_y;
}

//MODIFIERS

void Point::SetX(double newxval) //SetX, which sets a (new) value for x coordinate
{
	m_x = newxval;
}

void Point::SetY(double newyval) //SetY, which sets a (new) value for x coordinate
{
	m_y = newyval;
}

std::string Point::ToString() // ToString() function to return string description of point of inputted coordinates x and y
{
	std::stringstream ss; //
	ss << "Point(" << m_x << "," << m_y << ")";
	return ss.str(); // String retrieval from string buffer
}