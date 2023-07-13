//ArrayException.hpp 
// Purpose: Creating an exception hierarchy with an ARRAYEXCEPTION base class and an OUTOFBOUNDSEXCEPTION derived class
//          Important point is that this header file includes most concepts seen previously 
// Modification dates: 11/28/2022 

#ifndef ArrayException_hpp
#define ArrayException_hpp
#include <string>

namespace AndrewGuerrand
{
    namespace Containers
    {
        class ArrayException
        { 
           public:

            //CONSTRUCTORS, DESTRUCTOR, COPY ASSIGNMENT, AND ASSIGNMENT OPERATOR

                ArrayException();                                               //Default constructor
                virtual ~ArrayException();                                      //Destructor

                virtual std::string GetMessage() const = 0;                     //GetMessage() function to display an error message made to be a pure virtual member function
                
        };
    }
}

#endif