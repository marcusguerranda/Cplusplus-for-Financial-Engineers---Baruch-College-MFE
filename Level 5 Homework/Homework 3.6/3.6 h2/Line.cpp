// Line.cpp 
// Purpose: Source file for line file Line.hpp. Contains constructor, destructor, copy assignment, setters, and getters. We use virtual ToString(), and call Shape::ToString()
// Modification dates: 11/28/2022 


#include "Line.hpp"     //Header file that contains declarations about lines
#include "Point.hpp"    //Header file that contains declarations about points
#include "Shape.hpp"    //Header file that contains declarations for shape class




namespace AndrewGuerrand
{
    namespace CAD
    {
        //CONSTRUCTOR, DESTRUCTOR, COPY ASSIGNMENT, AND ASSIGNMENT OPERATOR

            Line::Line(): Shape(), p_starting(0.0, 0.0), p_ending(0.0, 0.0)            
            {
                //Default constructor using point default constructor, and shape default constructor
                //std::cout << "User, a new LINE in DEFAULT CONSTRUCTOR was CREATED." << std::endl;
            }

            Line::Line(const Point& starting, const Point& ending): Shape(), p_starting(starting), p_ending(ending)  
            {
                //Constructor with two given points, start and end, as well as calling of default shape constructor
                //std::cout << "User, a new line in OVERLOADED CONSTRUCTOR was CREATED." << std::endl;
            }

            Line::Line(const Line &source): Shape(source), p_starting(source.p_starting), p_ending(source.p_ending)                        
            {
                //Copy constructor of referenced line, and calling of copy constructor in shape class
                //std::cout << "User, a new line in COPY CONSTRUCTOR was CREATED." << std::endl;
            }

            Line& Line::operator = (const Line &source)                  
            {
                //Assignment operator
                if (this == &source)
                {
                    //std::cout << "AAAAAAA" << std::endl;
                    return *this;                                   //Self-assignment as discussed in lecture 2-04
                }
                else
                {
                    Shape::operator = (source);                             //Shape class assignment operator
                    p_starting = source.p_starting;
                    p_ending = source.p_ending;

                    //std::cout << "ASSIGNMENT OPERATOR USED IN LINE.CPP ." << std::endl;

                    return *this;                                   //Current object is returned
                }
            }


            Line::~Line()                                           
            {
                //Destructor
                //std::cout << "User, a line was DESTROYED." << std::endl;
            }

        //GETTERS / SELECTORS

            const Point& Line::P1() const                           //Getter function that returns the value of the starting point of a line
            {
                return p_starting;
            }

            const Point& Line::P2() const                           //Getter function that returns the value of the ending point of a line
            {
                return p_ending;
            }

            void Line::P1(const Point &source)
            {
                p_starting = source;                                //See instance definition line 16 and 17 in "TestPoint.cpp"
            }

            void Line::P2(const Point& source)
            {
                p_ending = source;                                  //See instance definition line 16 and 17 in "TestPoint.cpp"
            }

            void Line::Draw() const									//Defining of Draw() method 
       	 	{
            	std::cout << "User, a LINE is being DRAWN !" << std::endl;
        	}

        //SETTERS/ MODIFIERS

            std::string Line::ToString() const                      //Function that returns a description of of the line
            {
                // We retrieve x and y coordinates for both starting and ending points with the functions X and Y defined in "Point.cpp"
				std::string s = Shape::ToString();					//Calling ToString() method of the Shape base class
                std::stringstream ss; 
                ss << s << " Line starting with: " <<  p_starting << "and ending with: " << p_ending << std::endl;
                return ss.str();                                    // String retrieval from string buffer
            }

            double Line::Length() const                             //See "Point.cpp" in the defining of the Distance function
            {
                return  p_starting.Distance(p_ending);
            }

            std::ostream& operator << (std::ostream& os, const Line& source)
            {
                os << source.ToString(); 										//Sending to os stream
                return os;
            }
    }        
}
