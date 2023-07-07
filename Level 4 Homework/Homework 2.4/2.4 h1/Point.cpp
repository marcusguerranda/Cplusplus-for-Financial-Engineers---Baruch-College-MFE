// Point.cpp 
// Purpose: Source file for header file Point.hpp
// Modification dates: 11/20/2022 


#include "Point.hpp"	//Header file that contains declarations
#include <sstream>		//C++ stream buffering
#include <cmath>		// Math functions used in distance calculations
#include <iostream>

//CONSTRUCTOR AND DESTRUCTOR

Point::Point():m_x(0), m_y(0)	//Default constructor, and list initialization method as seen further in Lecture 3-04
{
}

Point::Point(double newxval, double newyval): m_x(newxval), m_y(newyval) 
{
}

Point::Point(const Point &p): m_x(p.m_x), m_y(p.m_y)					//Copy constructor using reference value of abstract instance p at creation
{
}

Point& Point::operator = (const Point &p)								//Assignment operator to avoid unnecessary copy of object, as seen in 2-04- Basic Operator Overloading
{
	if (this == &p)
	{
		return *this;													//Self-assignment as discussed in lecture 2-04
	}
	else
	{
		m_x = p.m_x;
		m_y = p.m_y;

		return *this;													//Current object is returned
	}

}

Point::~Point()															// Destructor
{
}


//SELECTORS

double Point::X() const 												//GetX function that gets private variable x in Point class, and returns it
{
	return m_x;
}

double Point::Y() const 												//GetY function that gets private variable y in Point class, and returns it
{
	return m_y;
}

//MODIFIERS

void Point::X(double newxval) 											//SetX, which sets a (new) value for x coordinate
{
	m_x = newxval;
}

void Point::Y(double newyval) 											//SetY, which sets a (new) value for x coordinate
{
	m_y = newyval;
}

std::string Point::ToString() const 									// ToString() function to return string description of point of inputted coordinates x and y
{
	std::stringstream ss; 
	ss << "Point(" << m_x << "," << m_y << ") ";
	return ss.str(); 													// String retrieval from string buffer
}

double Point::Distance() const 											//Defining distance between a point and its origin
{							
	return std::sqrt(pow(m_x, 2) + pow(m_y, 2)); 						//Computing distance, direct derivation from Pythagoras theorem. For two points (x,y) and (a,b), their distance is:
}                                                      					//  sqr( (x-a)^2 + (y-b)^2 )

double Point::Distance(const Point &p) const 							//Defining distance between two points; using call by reference
{
	return std::sqrt(pow((m_x - p.m_x), 2) + pow((m_y - p.m_y), 2));	//Same distance formula, but with two different points and their respective x and y coordinates
}

Point Point::operator - () const										//Negate the coordinates
{
	return Point(-m_x, -m_y);
}

Point Point::operator * (double factor) const							//Scale the coordinates
{
	return Point(m_x*factor, m_y*factor);
}

Point Point::operator + (const Point &p) const							//Add coordinates
{
	return Point (m_x+p.m_x, m_y+p.m_y);
}

bool Point::operator == (const Point &p) const							//Equally compare operator
{
	return (m_x == p.m_x && m_y ==p.m_y);								//Returns boolean value
}
	
Point& Point::operator *= (double factor)								//Scale the coordinates and assignment					
{
	m_x *= (factor);
	m_y *= (factor);

	return *this;
}		
        