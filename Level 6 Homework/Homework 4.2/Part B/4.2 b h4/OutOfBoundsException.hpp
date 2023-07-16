//OutOfBoundsException.hpp 
// Purpose: Creating an exception hierarchy with an ARRAYEXCEPTION base class and an OUTOFBOUNDSEXCEPTION derived class
//          Important point is that this header file includes most concepts seen previously (const ref, virtual member function (VMF), and more)
// Modification dates: 11/29/2022 


#ifndef OutOfBoundsException_hpp
#define OutOfBoundsException_hpp


#include "ArrayException.hpp"               //Header with definitions of ArrayException baseclass methods

namespace AndrewGuerrand
{
    namespace Containers
    {
            class OutOfBoundsException: public ArrayException                    //Derived class of base class ArrayException
                    {
                        private:
                            int m_index;                                         //Index data member for out of bound
                        
                        public:
                        
                    //CONSTRUCTORS, DESTRUCTOR, COPY ASSIGNMENT, AND ASSIGNMENT OPERATOR

                            OutOfBoundsException();                                                     //Default constructor
                            OutOfBoundsException(int index);                                            //Overload constructor
                            virtual ~OutOfBoundsException();                                            //Destructor

                            virtual std::string GetMessage() const;                                     //GetMessage() function to display an error message made


                    };
    }
}

#endif