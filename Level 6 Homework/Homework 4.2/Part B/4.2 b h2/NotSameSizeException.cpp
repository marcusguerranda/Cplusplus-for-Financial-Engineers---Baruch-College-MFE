// NotSameSizeException.cpp 
// Purpose: Source file of NotSameSixeException class using templates
//          Creating an exception hierarchy with an ARRAYEXCEPTION base class and an NOTSAMESIZE derived class
//
// Modification dates: 12/9/2022 



#ifndef NotSameSizeException_cpp
#define NotSameSizeException_cpp

#include "NotSameSizeException.hpp"                                                 //Header file NotSameSizeException to deal with array exceptions
#include <sstream>                                                                  //Stringstream library from STL


namespace AndrewGuerrand
{
    namespace Containers
    {
                     //CONSTRUCTORS, DESTRUCTOR

                        //Default constructor, creating base class object and derived instance by defaulting array_size to 0
                        NotSameSizeException:: NotSameSizeException() : ArrayException(), array_size(0)    
                       {
                            //std::cout << "NotSameSizeException Default constructor used." << std::endl;
                        }
                        
                        //Overload constructor
                        NotSameSizeException:: NotSameSizeException(int size) : ArrayException(), array_size(size)    
                        {
                            //std::cout << "NotSameSizeException OVERLOADED constructor used." << std::endl;
                        }

                        //Virtual Destructor
                        NotSameSizeException::~NotSameSizeException()
                        {
                            //std::cout << "NotSameSizeException DESTRUCTOR used." << std::endl;
                        }
                        
                        //GetMessage() function to display an error message made
                        std::string NotSameSizeException:: GetMessage() const                     
                        {
                            std::stringstream ss;
                            ss << "User, the arrays are NOT of the same size." << std::endl;
                            return ss.str();
                        }
    }
}


#endif