// Shape.cpp 
// Purpose: Source file of shape abstract class, including defining of default constructor, destructor, copy constructor, assignment operator, ID() function and ToString() function
// Modification dates: 11/27/2022 

#include "Shape.hpp"


//CONSTRUCTORS AND DESTRUCTOR, ASSIGNMENT OPEATOR

namespace AndrewGuerrand
{
    namespace CAD
    {
            Shape::Shape(): m_id(rand())      //Default constructor; generating a random ID number with rand() function
            {                                              
                //std::cout << "Shape DEFAULT constructor." << std::endl;
            }

            Shape::~Shape()                   //Destructor
            {
                //std::cout << "Shape DESTRUCTOR used." << std::endl;
            }                                      

            Shape::Shape(const Shape& source): m_id(source.m_id)                          //Copy constructor
            {
                //std::cout << "Shape COPY CONSTRUCTOR USED." << std::endl;                   
            }

            Shape& Shape::operator = (const Shape& source)                               //Assignment Operator
            {
                if (this == &source)
                    return *this;
                
                else
                {
                    m_id = source.m_id;
                    return *this;
                }
            }


            //GETTER/SELECTORS

            std::string Shape::ToString() const        //ToString() function that returns the ID string as string
            {
                std::stringstream ss;
                ss << "ID:" << m_id;
                return ss.str();
            }
                            
            int Shape::ID() const                      //Getter function to retrieve private ID data member
            {
                return m_id;
            }
    }
}