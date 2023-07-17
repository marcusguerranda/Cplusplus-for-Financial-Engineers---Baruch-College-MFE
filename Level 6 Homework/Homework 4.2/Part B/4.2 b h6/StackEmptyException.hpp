//StackEmptyException.hpp
//
//Purpose: (header file) Derived class of abstract base class StackException
//
//Modified Dates: 12/16/2022


#ifndef StackEmptyException_hpp
#define StackEmptyException_hpp

#include "StackException.hpp"                           //StackException Header file

namespace AndrewGuerrand
{
    namespace Containers
    {
        class StackEmptyException: public StackException
        {
            public:
        //CONSTRUCTORS
            StackEmptyException();                       //Default constructor
            virtual ~StackEmptyException();              //Virtual destructor

            virtual std::string GetMessage() const;      //GetMessage() function to display an error message made

        };
    }
}

#endif