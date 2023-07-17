//StackException.hpp
//
//Purpose: Base class for stack exemptions (stack being full or empty exceptions, for example)
//Modification dates: 12/16/2022


#ifndef StackException_hpp
#define StackException_hpp
#include <string>

namespace AndrewGuerrand
{   
    namespace Containers
    {
        class StackException 
        {
        public:
        
    //CONSTRUCTORS, DESTRUCTOR, GETMESSAGE

        StackException(){};                             //Default constructor
        virtual ~StackException(){};                    //Virtual Destructor (Pure virtual member function, making StackException an abstract base class)

        virtual std::string GetMessage() const = 0;     //GetMessage() function to display an error message made to be a pure virtual member function
        };
    }
}

#endif





