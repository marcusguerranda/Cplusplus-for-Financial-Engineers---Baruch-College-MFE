// Point.cpp 
// Purpose: Source file for header file Point.hpp Contains constructor, destructor, copy assignment, assignment overloadings, calculating distance functions
//			We use virtual ToString(), and call Shape::ToString()
// Modification dates: 11/28/2022 


#include "Point.hpp"	//Header file that contains declarations for Point class
#include "Shape.hpp"	//Header file that contains declarations for Shape class
#include <cmath>


namespace AndrewGuerrand
{
	namespace CAD
	{
	//CONSTRUCTOR AND DESTRUCTOR 

			Point::Point(): Shape(), m_x(0.0), m_y(0.0) 	
			{
				//Default constructor, and calling of Shape() default constructor
				//std::cout << "User, a new point in DEFAULT CONSTRUCTOR was created." << std::endl;
			}

			Point::Point(double newxval, double newyval): Shape(), m_x(newxval), m_y(newyval)
			{
				//Overloaded point constructor, and calling of default shape constructor
				//std::cout << "User, a new point in OVERLOADED CONSTRUCTOR (two arguments) was created." << std::endl;
			}

			Point::Point(const Point &source): Shape(source), m_x(source.m_x), m_y(source.m_y)		
			{	
				//Copy constructor using reference value of abstract instance p at creation; using shape copy constructor with a given shape abstract instance
				//std::cout << "User, a point was copied with copy constructor." << std::endl;
			}

			Point& Point::operator = (const Point &source)
			{
				//Assignment operator to avoid unnecessary copy of object, as seen in 2-04- Basic Operator Overloading
				if (this == &source)
				{
					return *this;														//Self-assignment as discussed in lecture 2-04
				}
				else
				{
					Shape::operator = (source);                             					//Shape class assignment operator
					m_x = source.m_x;
					m_y = source.m_y;
					//std::cout << "ASSIGNMENT OPERATOR USED IN POINT.CPP" << std::endl;
					return *this;														//Current object is returned
				}

			}

			Point::~Point()																// Destructor
			{
				//std::cout << "User, a point was DESTROYED." << std::endl;
			}


		//SELECTORS

			double const &Point::X() const 												//GetX function that gets private variable x in Point class, and returns it
			{
				return m_x;
			}

			double const &Point::Y() const 												//GetY function that gets private variable y in Point class, and returns it
			{
				return m_y;
			}

			void Point::Draw() const													//Defining of Draw() method 
       	 	{
            	std::cout << "User, a POINT is being DRAWN !" << std::endl;
        	}

		//MODIFIERS

			void Point::X(double newxval) 												//SetX, which sets a (new) value for x coordinate
			{
				m_x = newxval;
			}

			void Point::Y(double newyval) 												//SetY, which sets a (new) value for x coordinate
			{
				m_y = newyval;
			}

			std::string Point::ToString() const 									//ToString() function to return string description of point of inputted coordinates x and y
			{
				std::string s = Shape::ToString();									//Calling ToString() method of the Shape base class
				std::stringstream ss; 
				ss << s << " Point(" << m_x << "," << m_y << ") ";
				return ss.str(); 													// String retrieval from string buffer
			}

			double Point::Distance() const 											//Defining distance between a point and its origin
			{							
				return std::sqrt(pow(m_x, 2) + pow(m_y, 2)); 						//Computing distance, direct derivation from Pythagoras theorem. For two points (x,y) and (a,b), their distance is:
			}                                                      					//  sqr( (x-a)^2 + (y-b)^2 )

			double Point::Distance(const Point &source) const 							//Defining distance between two points; using call by reference
			{
				return std::sqrt(pow((m_x - source.m_x), 2) + pow((m_y - source.m_y), 2));	//Same distance formula, but with two different points and their respective x and y coordinates
			}

			Point Point::operator - () const										//Negate the coordinates
			{
				return Point(-m_x, -m_y);
			}

			Point Point::operator * (double factor) const							//Scale the coordinates
			{
				return Point(m_x*factor, m_y*factor);
			}

			Point Point::operator + (const Point &source) const							//Add coordinates
			{
				return Point (m_x+source.m_x, m_y+source.m_y);
			}

			bool Point::operator == (const Point &source) const							//Equally compare operator
			{
				return (m_x == source.m_x && m_y ==source.m_y);								//Returns boolean value
			}
				
			Point& Point::operator *= (double factor)								//Scale the coordinates and assignment					
			{
				m_x *= (factor);
				m_y *= (factor);

				return *this;
			}		

			std::ostream& operator << (std::ostream& os, const Point& source)
			{
				os << source.ToString(); 												//Sending to os stream
				return os;
			}
	}		

}