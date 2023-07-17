//StackFullException.hpp
//
//Purpose: (source file) Derived class of abstract base class StackException
//
//Modified Dates: 12/16/2022

#ifndef StackFullException_cpp
#define StackFullException_cpp

#include "StackFullException.hpp"                       //StackFullException Header file
#include <sstream>

namespace AndrewGuerrand
{
    namespace Containers
    {
    
        StackFullException::StackFullException()                    //Default constructor
        {
            //std::cout << "StackFullException DEFAULT constructor used." << std::endl;
        }

        StackFullException::~StackFullException()                   //Virtual destructor
        {
            //std::cout << "StackFullException DESTRUCTOR used." << std::endl;       
        }

        std::string StackFullException::GetMessage() const          //GetMessage() function to display an error message made
        {
           std::stringstream ss;
           ss << "User, stack is FULL.";
           return ss.str(); 
        }

        
    }
}

#endif