// Circle.cpp 
// Purpose: Source file for line file Line.hpp
// Modification dates: 11/27/2022 


#define _USE_MATH_DEFINES
#include <cmath>        //Math functions used in distance calculations and default M_PI value for PI
#include "Circle.hpp"   //Header file that contains declarations about circles
#include "Point.hpp"    //Header file that contains declarations about points
#include "Line.hpp"     //Header file that contains declarations about lines

namespace AndrewGuerrand
{ 
    namespace CAD
    {

            //CONSTRUCTORS AND DESTRUCTOR

            Circle::Circle(): m_center(Point(0,0)), m_radius(0)                                                
            {//Default constructor, and list initialization method as seen further in Lecture 3-04
    
                //m_center = Point(0,0);
                //m_radius = 0.0;
                //std::cout << "User, a new CIRCLE in DEFAULT CONSTRUCTOR was CREATED." << std::endl;
            }       

            Circle::Circle(const Point &center, const double &radius): m_center(center), m_radius(radius)      
            { //Constructor for circle object taking radius and center point coordinates

                //m_center = center;
                //m_radius = radius;
                //std::cout << "User, a new CIRCLE in OVERLOADED CONSTRUCTOR was CREATED." << std::endl;
            }

            Circle::Circle(const Circle &source): m_center(source.m_center), m_radius(source.m_radius)    
            {//Copy constructor of another circle object

                //m_center = c.m_center;
                //m_radius = c.m_radius;
                //std::cout << "COPY CONSTRUCTOR USED IN CIRCLE.CPP ." << std::endl;
            }

            Circle& Circle::operator = (const Circle &source)                    
            {//Assignment operator

                if (this == &source)
                {
                    return *this;                                           //Self-assignment as discussed in lecture 2-04
                }
                else
                {
                    m_radius = source.m_radius;
                    m_center = source.m_center;

                    return *this;                                           //Current object is returned
                }
                
            }

            Circle::~Circle()                                               //Destructor
            {//Destructor
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


            // MODIFIERS:

            void Circle::Radius(const double &radius)           //Radius function taking as argument a reference value 'radius'.    
            {
                m_radius = radius;
            }

            std::string Circle::ToString() const
            {
                //Printing out information on the circle, such as on the centerpoint, the radius, circumference, and area.

                std::stringstream ss; 
                ss << "This circle has for center: " << m_center.ToString() << ", and for radius: " << m_radius; //Information about the center of the circle and its radius
                return ss.str(); // String retrieval from string buffer

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