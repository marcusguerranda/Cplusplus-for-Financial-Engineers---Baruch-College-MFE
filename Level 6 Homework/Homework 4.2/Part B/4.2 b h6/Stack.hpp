// Stack.hpp 
// Purpose: Stack class header file using composition and delegation.
//          Push() and Pop() functions are defined, with m_current as a data member.
//          Exception handling is moved onto StackException
// Modification dates: 12/11/2022 



#ifndef Stack_hpp
#define Stack_hpp
#include "Array.hpp"                //Header file for Array


namespace AndrewGuerrand
{
    namespace Containers
    {
        template <typename T, int size> class Stack
        {  
        private:
    //DATA MEMBERS

            int m_current;          //Data member storing current index of array
            Array<T> m_array;       //Array used for storage of data 

        public:
    //CONSTRUCTORS, DESTRUCTOR, AND ASSIGNMENT OPERATOR

            Stack();                                        //Default constructor
            Stack(const Stack<T,size>& source);             //Copy constructor
            Stack<T,size>& operator = (const Stack<T,size>& source);  //Assignment operator
            virtual ~Stack();                               //Destructor

    //FUNCTIONS

            void Push(T element);                           //Push function that stores the element at the current position in the embedded array, and then increment position
            T Pop();                                        //Pop function that that decrements the current position and then returns the element at that position 
            int GetCurrentIndex();
        };
    }
}


#ifndef Stack_cpp
#include "Stack.cpp"
#endif



#endif