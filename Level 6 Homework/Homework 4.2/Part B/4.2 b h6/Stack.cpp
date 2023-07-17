// Stack.cpp 
// Purpose: Stack class source file using composition and delegation.
//          Push() and Pop() functions are defined, with m_current as a data member.
//          Exception handling is moved onto StackException
// Modification dates: 12/11/2022 


#ifndef Stack_cpp
#define Stack_cpp
#include "Stack.hpp"                        //Header file for Stack class
#include "NotSameSizeException.hpp"         //Header file taking care of exceptions in regard to size mismatch between more than one array
#include "OutOfBoundsException.hpp"         //Header file taking care of exceptions in regard to indices out of bounds
#include "StackEmptyException.hpp"          //Header file taking care of exceptions when stack is empty
#include "StackFullException.hpp"           //Header file taking care of exceptions when stack is full
#include "StackException.hpp"           //Header file taking care of exceptions when stack is full

#include <iostream>

namespace AndrewGuerrand
{
    namespace Containers
    {
    //CONSTRUCTORS, DESTRUCTOR, AND ASSIGNMENT OPERATOR
        
    //Default constructor
        template <typename T, int size>
        Stack<T,size>::Stack(): m_current(0), m_array(size)                                         
        {
            //std::cout << "User, Stack DEFAULT constructor used." << std::endl;
        }


    //Copy operator
        template <typename T, int size>
        Stack<T,size>::Stack(const Stack<T,size>& source): m_current(source.m_current), m_array(source.m_array)               
        {
            //std::cout << "User, Stack COPY constructor used." << std::endl;
        }

    //Assignment operator
        template <typename T, int size>
        Stack<T,size>& Stack<T,size>::operator = (const Stack<T,size>& source)
        {
            if (this == &source)
            {  
                return *this;
            }
            else
            {
                m_current = source.m_current;
                m_array = source.m_array;
                return *this;
            }
        }
        

    //Destructor
        template <typename T, int size>  
        Stack<T,size>::~Stack()                                          
        {
            //std::cout << "User, Stack DESTRUCTOR  used." << std::endl;
        }

    //FUNCTIONS
    
    //Push function that stores the element at the current position in the embedded array, and then increment position
        template <typename T, int size>
        void Stack<T,size>::Push(T element)        
        {
            try
            {
                m_array[m_current] = element;               //Store the element at the current position 
                std::cout << "Index " << m_current <<": " << m_array[m_current] << std::endl;
                m_current++;                                //Increment current position afterwards   
            }
            catch(OutOfBoundsException& exception)
            {
                throw StackFullException();
            }
            catch(...)
            {
                std::cout << "User, an unhandled exception has been encountered." << std::endl;
            }
        }

    //Pop function that that decrements the current position and then returns the element at that position
        template <typename T, int size>
        T Stack<T,size>::Pop()                               
        {
            try
            {
                if (m_current == 0)
                {
                    return m_array[m_current-1];    //By this current 'structure' if index ==0, the index will not change when stack is empty since exception thrown (stackexception)
                }
                else
                {
                    return m_array[--m_current];   
                }      
            }
            catch(OutOfBoundsException& exception)
            {
                m_current = 0;                      //If StackFullException thrown, set current index back to 0
                throw StackEmptyException();
            }
            catch(...)
            {
                std::cout << "User, an unhandled exception has been encountered." << std::endl;
            }
            return 0;
        }


        template <typename T, int size>
        int Stack<T,size>::GetCurrentIndex()
        {
            return m_current; 
        }          
        
    }
}


#endif