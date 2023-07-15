// NotSameSizeException.hpp 
// Purpose: Header file of NotSameSixeException class using templates
//          Creating an exception hierarchy with an ARRAYEXCEPTION base class and an NOTSAMESIZE derived class
//
// Modification dates: 12/9/2022 


#ifndef NotSameSizeException_hpp
#define NotSameSizeException_hpp

#include "ArrayException.hpp"                                                   //Header file ArrayException to deal with array exceptions

namespace AndrewGuerrand
{
    namespace Containers
    {
            class NotSameSizeException: public ArrayException                            //Derived class of base class ArrayException
                    {
                        private:
                
                            int array_size;                                              //Private data member containing array size
                        
                        public:
                        
                    //CONSTRUCTORS, DESTRUCTOR, COPY ASSIGNMENT, AND ASSIGNMENT OPERATOR

                            NotSameSizeException();                                      //Default constructor
                            NotSameSizeException(int index);                             //Overloaded constructor
                            virtual ~NotSameSizeException();                             //Virtual Destructor

                            virtual std::string GetMessage() const;                      //GetMessage() function to display an error message made


                    };
    }
}


#endif