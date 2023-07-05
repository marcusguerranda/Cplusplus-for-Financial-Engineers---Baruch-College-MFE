// Point.cpp 
// Purpose: Source file for header file Point.hpp
// Modification dates: 11/16/2022 


#include "Point.hpp" //Header file that contains declarations
#include <sstream>
#include <cmath>

//CONSTRUCTOR AND DESTRUCTOR

Point::Point(): m_x(0), m_y(0) // Default constructor, using initialization list method
{
	// m_x =0;
	// m_y =0;
}

Point::~Point()	// Destructor
{
}


//SELECTORS

double Point::GetX()	//GetX function that gets private variable x in Point class, and returns it
{
	return m_x;
}

double Point::GetY()	//GetY function that gets private variable y in Point class, and returns it
{
	return m_y;
}


//MODIFIERS

void Point::SetX(double newxval)	//SetX, which sets a (new) value for x coordinate
{
	m_x = newxval;
}

void Point::SetY(double newyval)	//SetY, which sets a (new) value for x coordinate
{
	m_y = newyval;
}

std::string Point::ToString()		//ToString() function to return string description of point of inputted coordinates x and y
{
	std::stringstream ss; 
	ss << "Point(" << m_x << "," << m_y << ")";
	return ss.str(); 				//String retrieval from string buffer
}

double Point::DistanceOrigin()		//Defining distance between a point and its origin
{							
	return std::sqrt(pow(m_x, 2) + pow(m_y, 2)); //Computing distance, direct derivation from Pythagoras theorem. For two points (x,y) and (a,b), their distance is:
}                                                //  sqr( (x-a)^2 + (y-b)^2 )

double Point::Distance(Point p)
{
	return std::sqrt(pow((m_x - p.m_x), 2) + pow((m_y - p.m_y), 2)); //Same distance formula, but with two different points and their respective x and y coordinates
}