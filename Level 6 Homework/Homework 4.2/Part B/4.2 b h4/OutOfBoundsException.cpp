//OutOfBoundsException.cpp 
// Purpose: Creating an exception hierarchy with an ARRAYEXCEPTION base class and an OUTOFBOUNDSEXCEPTION derived class
//          Here, this is the source file for the derived class OutOfBoundsException of the base class ArrayException
// Modification dates: 11/29/2022 


#include "OutOfBoundsException.hpp"               //Header with definitions of OutOfBoundsException baseclass methods
#include <sstream>

namespace AndrewGuerrand
{
    namespace Containers
    {
                    //CONSTRUCTORS, DESTRUCTOR,and GetMessage()

                            OutOfBoundsException::OutOfBoundsException(): ArrayException(), m_index(0)               //Default constructor
                            {
                                //std::cout << "OutOfBoundsException Default constructor used." << std::endl;
                            }
                           
                           OutOfBoundsException::OutOfBoundsException(int index): ArrayException(), m_index(index)   //Overload constructor
                            {
                                //std::cout << "OutOfBoundsException overload constructor used." << std::endl;
                            }

                           
                            OutOfBoundsException::~OutOfBoundsException()                                            //Destructor
                            {
                                //std::cout << "OutOfBoundsException DESTRUCTOR used." << std::endl;
                            }


                            std::string OutOfBoundsException::GetMessage() const                                     //GetMessage() function to display an error message made
                            {
                                std::stringstream ss;
                                ss << "User, index number " << m_index << " is currently out of bounds.";
                                return ss.str(); 
                            }

                    
    }
}
