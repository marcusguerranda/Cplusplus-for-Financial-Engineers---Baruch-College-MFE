// Shape.hpp 
// Purpose: Header file of shape abstract class, including default constructor, destructor, copy constructor, assignment operator, ID() function and ToString() function
//          Use of the virtual ToString() function for proper call of ToString() function when dealing with different derived classes' objects.
// Modification dates: 11/27/2022 


#ifndef Shape_hpp
#define Shape_hpp
#include <string>
#include <sstream>
#include <iostream>
#include "stdlib.h"

namespace AndrewGuerrand
{
    namespace CAD
    {        
            class Shape
            {
                private:
            //DATA MEMBERS
                        
                int m_id;	// ID 

                public:
            //CONSTRUCTORS AND DESTRUCTOR
                        
                Shape();                                     //Default constructor
                ~Shape();                                    //Destructor
                Shape(const Shape& source);                  //Copy constructor
                Shape& operator = (const Shape& source);     //Assignment operator

            //GETTER/SELECTORS

                virtual std::string ToString() const;       //ToString() that returns the ID as string
                int ID() const;                             //Getter function to retrieve private ID data member 
            };
    }
}

#endif