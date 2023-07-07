// Point.cpp 
// Purpose: Source file for header file Point.hpp
// Modification dates: 11/17/2022 

#include "Point.hpp" //Header file that contains declarations
#include <sstream> //C++ stream buffering 
#include <iostream> //C++ I/O
#include <cmath> // Math functions used in distance calculations

//CONSTRUCTOR AND DESTRUCTOR

Point::Point():m_x(0), m_y(0) // Default constructor
{
}

Point::Point(double newxval, double newyval): m_x(newxval), m_y(newyval) 
{
}

Point::Point(const Point &p)  //Copy constructor using reference value of abstract instance p at creation
{
	m_x = p.m_x;
	m_y = p.m_y;
}


Point::~Point()	// Destructor
{
}

//MODIFIERS

std::string Point::ToString() const // ToString() function to return string description of point of inputted coordinates x and y
{
	std::stringstream ss; 
	ss << "Point(" << m_x << "," << m_y << ") ";
	return ss.str(); // String retrieval from string buffer
}

double Point::Distance() const //Defining distance between a point and its origin
{							
	return std::sqrt(pow(m_x, 2) + pow(m_y, 2)); //Computing distance, direct derivation from Pythagoras theorem. For two points (x,y) and (a,b), their distance is:
}                                                //sqr( (x-a)^2 + (y-b)^2 )

double Point::Distance(const Point &p) const ////Defining distance between two points; using call by reference
{
	return std::sqrt(pow((m_x - p.m_x), 2) + pow((m_y - p.m_y), 2)); //Same distance formula, but with two different points and their respective x and y coordinates
}