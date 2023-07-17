// Array.cpp 
// Purpose: Source file of array class using templates
//          This is an extension of previous exercises, using namespaces, const references, canonical header file principles and more.
//          We focus here most specificaly on how 'static' impacts the array default size
// Modification dates: 12/9/2022


#ifndef Array_cpp
#define Array_cpp
#include "Array.hpp"
#include "OutOfBoundsException.hpp"
#include <iostream>


namespace AndrewGuerrand
{
    namespace Containers
    {
    
    //CONSTRUCTORS AND DESTRUCTOR    
    
        template <typename T>                                                       // Static default size for array
        unsigned int Array<T>::m_default_size = 24;
        
        template <typename T>
        Array<T>::Array()
        {
            m_size = m_default_size;                                                //Size of array defaulted to statitc m_default_size = 24 
            m_data  = new T[m_size];                                                //Allocating 'm_size' elements to temporary array on the heap
            if(m_data == nullptr)
            {
                //std::cout << "User, no memory was available to temporarily store an array on the heap." << std::endl; //No memory available on theap
            }
            else
            {
                //std::cout << "User, a temporary default array has been created on the heap." << std::endl;
            }
        }

        template <typename T>
        Array<T>::Array(const int &given_size)                                                 //Constructor with size argument, taking const reference
        {
            m_size = given_size;                                                                    
            m_data = new T[m_size];                                                            //Creating an array on the heap with an input size argument
            if(m_data == nullptr)
            {
                //std::cout << "User, no memory was available to temporarily store an array on the heap." << std::endl;   //No memory available on theap
            }
            else
            {
                //std::cout << "User, a temporary default array has been created on the heap." << std::endl;              //Created array successfully
            }
        }                                                                                           

        template <typename T>
        Array<T>::Array(const Array<T> &source)                                                         //Copy constructor
        {
            m_size = source.m_size;                                                                     //Copying the same size of the array provided into our array
            m_data = new T[m_size];                                                                     //Creating the array with the same size as the array provided
            if(m_data == nullptr)
            {
                //std::cout << "User, no memory was available to temporarily store an array on the heap." << std::endl; //No memory available on theap
            }
            else
            {
                //std::cout << " User, copy of array has breen created on the heap." << std::endl;        
                for(int i = 0; i<m_size; i++)
                {
                    m_data[i] = source.m_data[i];
                }
                //std::cout << "User, all elements have been copied into the copie array." << std::endl;
            }
        }

        template <typename T>
        Array<T>::~Array()                                                                               //Destructor
        {
            delete [] m_data; 
            //std::cout << "User, array has been deleted from the heap." << std::endl;
        }

        template <typename T>
        Array<T>& Array<T>::operator = (const Array<T> &source)                                          //Assignment operator, as done previously for Point, Line, and Circle classes. 
        {
            if(this == &source)                                                                          //Precluding self-asignment
            {       
                return *this;
            }
            else
            {
                delete [] m_data;                                                                        //Delete any possible previous data in the array and the old C array itself
                m_size = source.m_size;                                                                  //Create a new array and copy each individual element with for-loop
                m_data = new T[m_size]; 

                for(int i = 0; i<m_size; i++)
                {
                    m_data[i] = source.m_data[i];
                }

                return *this;
            }
        }


        // SELECTORS/ GETTERS
        
        template <typename T>
        int const& Array<T>::Size() const                                               //Function that returns the size of the array
        {   
            return m_size;                  
        }

        template <typename T>
        const T& Array<T>::GetElement(int index) const                                  //Getter function. When the index is out of bounds, return the first element
        {
            if(index < m_size && index >= 0)                                            //Return the value at the specified index of the array
            {                                                                           //NOTE TO SELF: can't have negative indeces like in Python
                return m_data[index];
            }
            else                                                                        //If out of bounds, give the first value of the array
            {
                throw  OutOfBoundsException(index);   
            }
        }   

        template<typename T>
        unsigned int Array<T>::DefaultSize()                                            //Static getter function using template 
        {
            return m_default_size;
        }

        template <typename T>
        T& Array<T>::operator [] (int index)
        {
            if(index < m_size && index >= 0)                                            //When within bounds, return reference index, else return reference to first element
            {
                return m_data[index];
            }
            else
            {
                throw OutOfBoundsException(index);
            }
        }

        template <typename T>
        const T& Array<T>:: operator [] (int index) const
        {
            /*
            We have used const references in a similar fashion in getter function, when we are certain that no changes will be made to the arbitrary "object"
            we are "looking at". In effect, this const reference version permits the User to read and get a reference, without writing (which would be a likely alteration to a pointer
            in the array). 
            */

            if(index < m_size && index >= 0)                                           //When within bounds, return reference index, else return reference to first element
            {
                return m_data[index];
            }
            else
            {
                throw OutOfBoundsException(index);                                                              
            }
        }



        // MODIFIERS/ SETTERS

        template <typename T>
        void Array<T>::SetElement(const T& t, int index)                //Functions that sets an element. When the index is ount of bounds, ignore the "set"
        {                                                               //Using const reference for the point, and int value of the index for the array
            if(index < m_size && index >= 0)
            {
                m_data[index] = t;                                      //Set given Point's value(s) into m_data (pointer to a Point at index p_index in an array )
            }
            else
            {
                throw OutOfBoundsException(index);
            }
        }

        template <typename T>                                                           
        void Array<T>::DefaultSize(unsigned int size_default_setter)    //Static setter function using template
        {
             m_default_size = size_default_setter;
        }


    }
}

#endif