// Stack.cpp 
// Purpose: Stack class source file using composition and delegation.
//          Push() and Pop() functions are defined, with m_current as a data member.
// Modification dates: 12/11/2022 


#ifndef Stack_cpp
#define Stack_cpp
#include "Stack.hpp"
#include "NotSameSizeException.hpp"
#include <iostream>

namespace AndrewGuerrand
{
    namespace Containers
    {
    //CONSTRUCTORS, DESTRUCTOR, AND ASSIGNMENT OPERATOR
        
    //Default constructor
        template <typename T>
        Stack<T>::Stack(): m_current(0), m_array(Array<T>())                                         
        {
            //std::cout << "User, Stack DEFAULT constructor used." << std::endl;
        }

    //Overloaded constructor
        template <typename T>
        Stack<T>::Stack(const int& given_size): m_current(0), m_array(given_size)                     
        {
            //std::cout << "User, Stack OVERLOADED constructor used." << std::endl;
        }

    //Copy operator
        template <typename T>
        Stack<T>::Stack(const Stack<T>& source): m_current(source.m_current), m_array(source.m_array)               
        {
            //std::cout << "User, Stack COPY constructor used." << std::endl;
        }

    //Assignment operator
        template <typename T>
        Stack<T>& Stack<T>::operator = (const Stack<T>& source)
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
        template <typename T>  
        Stack<T>::~Stack()                                          
        {
            //std::cout << "User, Stack DESTRUCTOR  used." << std::endl;
        }

    //FUNCTIONS
    
    //Push function that stores the element at the current position in the embedded array, and then increment position
        template <typename T>
        void Stack<T>::Push(T element)        
        {
            m_array[m_current] = element;               //Store the element at the current position 
            std::cout << "Index " << m_current <<": " << m_array[m_current] << std::endl;
            m_current++;                                //Increment current position afterwards                                          
        }

    //Pop function that that decrements the current position and then returns the element at that position
        template <typename T>
        T Stack<T>::Pop()                               
        {
            if (m_current == 0)
            {
                return m_array[m_current-1];            //By this current 'structure' if index ==0, then 'Pop' will lead to an OutOfBoundsException, and thus index will not change.
            }
            else
            {
                return m_array[--m_current];   
            }      
        }


        template <typename T>
        int Stack<T>::Currentindex()
        {
            return m_current; 
        }          
        
    }
}


#endif