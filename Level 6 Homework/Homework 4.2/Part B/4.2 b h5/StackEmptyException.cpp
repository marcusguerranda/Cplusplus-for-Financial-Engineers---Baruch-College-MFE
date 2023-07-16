//StackEmptyException.cpp
//
//Purpose: (source file) Derived class of abstract base class StackException
//
//Modified Dates: 12/16/2022

#ifndef StackFullException_cpp
#define StackFullException_cpp

#include "StackEmptyException.hpp"                       //StackEmptyException Header file
#include <sstream>

namespace AndrewGuerrand
{
    namespace Containers
    {
    
        StackEmptyException::StackEmptyException()                      //Default constructor
        {
            //std::cout << "StackFullException DEFAULT constructor used." << std::endl;
        }

        StackEmptyException::~StackEmptyException()                     //Virtual destructor
        {
            //std::cout << "StackFullException DESTRUCTOR used." << std::endl;       
        }

        std::string StackEmptyException::GetMessage() const             //GetMessage() function to display an error message made
        {
           std::stringstream ss;
           ss << "User, stack is EMPTY.";
           return ss.str(); 
        }

    }
}

#endif