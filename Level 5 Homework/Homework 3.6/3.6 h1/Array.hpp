// Array.hpp 
// Purpose: Header file of array class
// Modification dates: 11/28/2022 

#ifndef Array_hpp
#define Array_hpp
#include "Point.hpp"                //Including point header file
#include <string>
#include <iostream>

namespace AndrewGuerrand
{
    namespace Containers
    {

        class Array
        {
        private:

        //DATA MEMBERS:

            CAD::Point *m_data;                  //Data member for a dynamic C array of Point objects
            int m_size;                         //Data member for the size of the array, as given in exercise


        public:

        // CONSTRUCTOR AND DESTRUCTOR

            Array();                                                //Default constructor
            Array(const int &given_size);                           //Constructor with size argument; implementation will allocate the number of elements specified by the size input argument
            Array(const Array &source);                             //Copy constructor for arrays
            Array &operator = (const Array &source);                //Assignment operator
            ~Array();                                               //Destructor

        // SELECTORS/ GETTERS
            
            int const &Size() const;                                             //Function that returns the size of the array, using const reference
            const CAD::Point &GetElement(int index) const;                       //Getter function. When the index is out of bounds, return the first element. Using const reference
            CAD::Point& operator [] (int index);                                 //Square bracket operator, returning a reference so the [] operator can be used for reading and writing elements
            const CAD::Point& operator [] (int index) const;                     //const square bracket operator --> see explanation in Array.cpp


        // MODIFIERS/SETTERS

            void SetElement(const CAD::Point& p, int p_index);                   //Functions that sets an element. When the index is ount of bounds, ignore the "set"
        };
    }
}

#endif