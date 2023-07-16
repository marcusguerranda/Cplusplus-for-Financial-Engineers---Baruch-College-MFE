//StackFullException.hpp
//
//Purpose: (header file) Derived class of abstract base class StackException
//
//Modified Dates: 12/16/2022


#ifndef StackFullException_hpp
#define StackFullException_hpp

#include "StackException.hpp"                           //StackException Header file

namespace AndrewGuerrand
{
    namespace Containers
    {
        class StackFullException: public StackException
        {
            public:
        //CONSTRUCTORS
            StackFullException();                       //Default constructor
            virtual ~StackFullException();              //Virtual destructor

            virtual std::string GetMessage() const;     //GetMessage() function to display an error message made

        };
    }
}

#endif