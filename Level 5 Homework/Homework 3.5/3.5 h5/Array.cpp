// Array.hpp 
// Purpose: Header file of array class
// Modification dates: 11/23/2022

#include "Array.hpp"
#include "Point.hpp"


//CONSTRUCTORS AND DESTRUCTOR

namespace AndrewGuerrand
{
    namespace Containers
    {
        Array::Array()
        {
            m_size = 10;                                                                               //Size of array defaulted to 10, as given in exercise
            m_data  = new CAD::Point[m_size];                                                          //Allocating 10 elements to temporary array on the heap
            if(m_data == nullptr)
            {
                std::cout << "User, no memory was available to temporarily store an array on the heap." << std::endl; //No memory available on theap
            }
            else
            {
                std::cout << "User, a temporary default array has been created on the heap." << std::endl;
            }
        }

        Array::Array(const int &given_size)                                                             //Constructor with size argument, taking const reference
        {
            m_size = given_size;                                                                    
            m_data = new CAD::Point[m_size];                                                            //Creating an array on the heap with an input size argument
            if(m_data == nullptr)
            {
                std::cout << "User, no memory was available to temporarily store an array on the heap." << std::endl; //No memory available on theap
            }
            else
            {
                std::cout << "User, a temporary default array has been created on the heap." << std::endl;  //Created array successfully
            }
        }                                                                                           

        Array::Array(const Array &source)                                                                //Copy constructor
        {
            m_size = source.m_size;                                                                      //Copying the same size of the array provided into our array
            m_data = new CAD::Point[m_size];                                                            //Creating the array with the same size as the array provided
            if(m_data == nullptr)
            {
                std::cout << "User, no memory was available to temporarily store an array on the heap." << std::endl; //No memory available on theap
            }
            else
            {
                std::cout << " User, copy of array has breen created on the heap." << std::endl;        
                for(int i = 0; i<m_size; i++)
                {
                    m_data[i] = source.m_data[i];
                }
                std::cout << "User, all elements have been copied into the copie array." << std::endl;
            }
        }


        Array::~Array()                                                                             //Destructor
        {
            delete [] m_data; 
            std::cout << "User, array has been deleted from the heap." << std::endl;
        }

        Array& Array::operator = (const Array &source)                                                   //Assignment operator, as done previously for Point, Line, and Circle classes. 
        {
            if(this == &source)                                                                          //Precluding self-asignment
            {       
                return *this;
            }
            else
            {
                delete [] m_data;                                                                   //Delete any possible previous data in the array and the old C array itself
                m_size = source.m_size;                                                                  //Create a new array and copy each individual element with for-loop
                m_data = new CAD::Point[m_size]; 

                for(int i = 0; i<m_size; i++)
                {
                    m_data[i] = source.m_data[i];
                }

                return *this;
            }
        }


        // SELECTORS/ GETTERS

        int const& Array::Size() const                                                  //Function that returns the size of the array
        {   
            return m_size;                  
        }


        const CAD::Point& Array::GetElement(int index) const                            //Getter function. When the index is out of bounds, return the first element
        {
            if(index <  m_size && index >= 0)                                           //Return the value at the specified index of the array
            {                                                                           //NOTE TO SELF: can't have negative indeces like in Python
                return m_data[index];
            }
            else                                                                        //If out of bounds, give the first value of the array
            {
                return m_data[0];   
                std::cout << "User, the index given was out of bounds. Here is the first value in the array." << std::endl;
            }
        }   

        CAD::Point& Array::operator [] (int index)
        {
            if(index <  m_size && index >= 0)                                           //When within bounds, return reference index, else return reference to first element
            {
                return m_data[index];
            }
            else
            {
                return m_data[0];
            }
        }

        const CAD::Point& Array:: operator [] (int index) const
        {
            /*
            We have used const references in a similar fashion in getter function, when we are certain that no changes will be made to the arbitrary "object"
            we are "looking at". In effect, this const reference version permits the User to read and get a reference, without writing (which would be a likely alteration to a pointer
            in the array). 
            */

            if(index <  m_size && index >= 0)                                           //When within bounds, return reference index, else return reference to first element
            {
                return m_data[index];
            }
            else
            {
                return m_data[0];
            }
        }



        // MODIFIERS/ SETTERS

        void Array::SetElement(const CAD::Point& source, int index)                     //Functions that sets an element. When the index is ount of bounds, ignore the "set"
        {                                                                               //Using const reference for the point, and int value of the index for the array
            if(index <  m_size && index >= 0)
            {
                m_data[index] = source;                                                 //Set given Point's value(s) into m_data (pointer to a Point at index p_index in an array )
            }
            else
            {
                //Ignore, for the purpose of this subexercise
            }
        }
    }
}