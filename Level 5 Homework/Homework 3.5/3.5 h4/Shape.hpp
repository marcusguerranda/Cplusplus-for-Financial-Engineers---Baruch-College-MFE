// Shape.hpp 
// Purpose: Header file of shape abstract class, including default constructor, destructor, copy constructor, assignment operator, ID() function and ToString() function
//          Use of the virtual ToString() function for proper call of ToString() function when dealing with different derived classes' objects.
// Modification dates: 11/28/2022 


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
                virtual ~Shape();                            //Destructor
                Shape(const Shape& source);                  //Copy constructor
                Shape& operator = (const Shape& source);     //Assignment operator
                virtual void Draw() const =  0;              //Draw() pure virtual member function (PVMF)

            //GETTER/SELECTORS

                virtual std::string ToString() const;       //ToString() that returns the ID as string
                int ID() const;                             //Getter function to retrieve private ID data member 
            };
    }
}

#endif