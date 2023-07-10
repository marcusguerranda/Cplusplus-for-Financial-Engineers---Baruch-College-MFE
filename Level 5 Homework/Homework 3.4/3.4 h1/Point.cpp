// Point.cpp 
// Purpose: Source file for header file Point.hpp
// Modification dates: 11/27/2022 


#include "Point.hpp"	//Header file that contains declarations
#include <cmath>        //Math functions used in distance calculations and default M_PI value for PI
namespace AndrewGuerrand
{
	namespace CAD
	{
	//CONSTRUCTOR AND DESTRUCTOR
			Point::Point(): m_x(0.0), m_y(0.0)
			{//Default constructor, and list initialization method as seen further in Lecture 3-04
				//m_x = 0.0;
				//m_y = 0.0;
				std::cout << "User, a new point in DEFAULT CONSTRUCTOR was created." << std::endl;
			}

			Point::Point(double newxval, double newyval): m_x(newxval), m_y(newyval)
			{
				//m_x = newxval;
				//m_y = newyval;
				std::cout << "User, a new point in OVERLOADED CONSTRUCTOR (two arguments) was created." << std::endl;
			}

			Point::Point(double testvalue): m_x(testvalue), m_y(testvalue)		
			{	//Constructor for a Point object taking one double value, and giving this value to both x and y coordinates		
				//m_x = testvalue;
				//m_y = testvalue;											
				std::cout << "User, a new line in OVERLOADED CONSTRUCTOR (one argument) was created." << std::endl; //m_x(testvalue), m_y(testvalue)
			}

			Point::Point(const Point &source): m_x(source.m_x), m_y(source.m_y)		
			{	//Copy constructor using reference value of abstract instance p at creation	
				//m_x = p.m_x;
				//m_y = p.m_y;
				std::cout << "User, a point was copied with copy constructor." << std::endl;
			}

			Point& Point::operator = (const Point &source)								//Assignment operator to avoid unnecessary copy of object, as seen in 2-04- Basic Operator Overloading
			{
				if (this == &source)
				{
					std::cout << "DDDDD" << std::endl;
					return *this;														//Self-assignment as discussed in lecture 2-04
				}
				else
				{
					m_x = source.m_x;
					m_y = source.m_y;
					std::cout << "ASSIGNMENT OPERATOR USED IN POINT.CPP" << std::endl;
					return *this;														//Current object is returned
				}

			}

			Point::~Point()																// Destructor
			{
				std::cout << "User, a point was DESTROYED." << std::endl;
			}


		//SELECTORS

			double const& Point::X() const 												//GetX function that gets private variable x in Point class, and returns it
			{
				return m_x;
			}

			double const& Point::Y() const 												//GetY function that gets private variable y in Point class, and returns it
			{
				return m_y;
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

			std::string Point::ToString() const 							//ToString() function to return string description of point of inputted coordinates x and y
			{
				std::stringstream ss; 
				ss << "Point(" << m_x << "," << m_y << ") ";
				return ss.str(); 											// String retrieval from string buffer
			}

			double Point::Distance() const 									//Defining distance between a point and its origin
			{							
				return std::sqrt(pow(m_x, 2) + pow(m_y, 2)); 				//Computing distance, direct derivation from Pythagoras theorem. For two points (x,y) and (a,b), their distance is:
			}                                                      			//  sqr( (x-a)^2 + (y-b)^2 )

			double Point::Distance(const Point &source) const 						//Defining distance between two points; using call by reference
			{
				return std::sqrt(pow((m_x - source.m_x), 2) + pow((m_y - source.m_y), 2));	//Same distance formula, but with two different points and respective x and y coordinates
			}

			Point Point::operator - () const												//Negate the coordinates
			{
				return Point(-m_x, -m_y);
			}

			Point Point::operator * (double factor) const									//Scale the coordinates
			{
				return Point(m_x*factor, m_y*factor);
			}

			Point Point::operator + (const Point &source) const								//Add coordinates
			{
				return Point (m_x+source.m_x, m_y+source.m_y);
			}

			bool Point::operator == (const Point &source) const								//Equally compare operator
			{
				return (m_x == source.m_x && m_y ==source.m_y);								//Returns boolean value
			}
				
			Point& Point::operator *= (double factor)										//Scale the coordinates and assignment					
			{
				m_x *= (factor);
				m_y *= (factor);

				return *this;
			}		

			std::ostream& operator << (std::ostream& os, const Point& source)
			{
				os << source.ToString(); 													//Sending to os stream
				return os;
			}
	}		

}