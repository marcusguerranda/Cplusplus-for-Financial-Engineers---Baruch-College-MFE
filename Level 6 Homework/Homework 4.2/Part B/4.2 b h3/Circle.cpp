// Circle.cpp 
// Purpose: Source file for line file Line.hpp. Contains constructor, destructor, copy assignment, setters, 
//          and getters such as calculating the area or circumference of circle. We use virtual ToString(), and call Shape::ToString()
// Modification dates: 11/28/2022 


#define _USE_MATH_DEFINES
#include "Circle.hpp"   //Header file that contains declarations about circles
#include "Point.hpp"    //Header file that contains declarations about points
#include "Line.hpp"     //Header file that contains declarations about lines
#include <cmath>

namespace AndrewGuerrand
{ 
    namespace CAD
    {

        //CONSTRUCTORS AND DESTRUCTOR

            Circle::Circle(): Shape(), m_center(Point()), m_radius(0.0)                                           
            {
                //Default constructor, and calling of shape default constructor in abstract class
                //std::cout << "User, a new CIRCLE in DEFAULT CONSTRUCTOR was CREATED." << std::endl;
            }       

            Circle::Circle(const Point &center, const double &radius): Shape(), m_center(center), m_radius(radius)      
            {
                //Constructor for circle object taking radius and center point coordinates, and calling of default constructor in shape abstract class
                //std::cout << "User, a new CIRCLE in OVERLOADED CONSTRUCTOR was CREATED." << std::endl;
            }

            Circle::Circle(const Circle &source): Shape(source), m_center(source.m_center), m_radius(source.m_radius)                    
            {
                //Copy constructor of another circle object, and calling of copy constructor in shape class  
                //std::cout << "COPY CONSTRUCTOR USED IN CIRCLE.CPP ." << std::endl;
            }

            Circle& Circle::operator = (const Circle &source)                   //Assignment operator
            {
                if (this == &source)
                {
                    return *this;                                               //Self-assignment as discussed in lecture 2-04
                }
                else
                {
                    Shape::operator = (source);                                 //Shape class assignment operator
                    m_radius = source.m_radius;
                    m_center = source.m_center;

                    return *this;                                               //Current object is returned
                }
                
            }

            Circle::~Circle()                                                   //Destructor
            {
                //std::cout << "User, a CIRCLE has been DESTROYED." << std::endl;
            }


        //SELECTORS:

            double const& Circle:: Radius() const
            {
                return m_radius;
            }

            Point const& Circle::CenterPoint() const  
            {
                return m_center;
            }

            void Circle::Draw() const											//Defining of Draw() method 
       	 	{
            	std::cout << "User, a CIRCLE is being DRAWN !" << std::endl;
        	}

        // MODIFIERS:

            void Circle::Radius(const double &radius)                           //Radius function taking as argument a reference value 'radius'.
            {
                m_radius = radius;
            }

            std::string Circle::ToString() const
            {
                //Printing out information on the circle, such as on the centerpoint, the radius, circumference, and area.
                std::string s = Shape::ToString();				//Calling ToString() method of the Shape base class
                std::stringstream ss; 
                ss << s << "This circle has for center: " << m_center.ToString() << ", and for radius: " << m_radius; //Information about the center of the circle and its radius
                return ss.str();                                // String retrieval from string buffer

            }

            double Circle::Diameter() const                     //Function calculating diameter of a circle: 2*Radius
            {
                return 2*(m_radius);                            
            }

            double Circle::Area() const                         //Formula for area of a circle: 2*PI*(Radius)^2
            {
                return 2*pow(m_radius,2)*M_PI;                  
            }

            double Circle::Circumference() const                //Function calculating circumference of a circle: 2*PI*Radius           
            {
                return 2*(M_PI)*(m_radius);
            }

            std::ostream& operator << (std::ostream &os, const Circle &source)
            {
                os << source.ToString(); 							//Sending to os stream
                return os;
            }
    }
}