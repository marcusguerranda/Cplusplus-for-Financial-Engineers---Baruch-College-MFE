//ArrayException.cpp 
// Purpose: Creating an exception hierarchy with an ARRAYEXCEPTION base class and an OUTOFBOUNDSEXCEPTION derived class
//          Important point is that this header file includes most concepts seen previously 
// Modification dates: 11/29/2022 

#include "ArrayException.hpp"       //Header file of base class ArrayException

namespace AndrewGuerrand
{
    namespace Containers
    {
             //CONSTRUCTORS, DESTRUCTOR, COPY ASSIGNMENT, AND ASSIGNMENT OPERATOR

                ArrayException::ArrayException()                                               //Default constructor
                {
                    //std::cout << "ArrayException Default constructor used." << std::endl;
                }

                ArrayException:: ~ArrayException()                                             //Destructor
                {
                    //std::cout << "ArrayException DESTRUCTOR used." << std::endl; 
                }
                
    }
}
