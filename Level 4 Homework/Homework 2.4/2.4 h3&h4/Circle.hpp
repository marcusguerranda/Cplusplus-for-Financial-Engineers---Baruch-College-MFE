// Circle.hpp 
// Purpose: Header file of circles defined in 2 dimensions
// Modification dates: 11/22/2022 

#ifndef Circle_hpp
#define Circle_hpp
            
#include "Point.hpp"            //Incuding Point header file
#include "Line.hpp"             //Including Line header file  
#include <sstream>              //C++ stream buffering 
#include <iostream>

class Circle
{

//DATA MEMBERS

private:
        
        Point m_center;         //Center point
        double m_radius;        //Radius

public:

// CONSTRUCTORS AND DESTRUCTORS

        Circle();                                           //Default constructor
        Circle(const Point &center, const double &radius);  //Constructor for circle object taking radius and center point coordinates
        Circle(const Circle &c);                            //Copy constructor of another circle object
        Circle& operator = (const Circle &c);               //Assignment operator
        ~Circle();                                          //Default destructor

// SELECTORS:

        double const &Radius() const;                       //Radius of a said circle
        Point const &CenterPoint() const;                   //Centerpoint

        friend std::ostream &operator << (std::ostream& os, const Circle& c);   //ToString() function to print description about circle
        std::string ToString() const;                                           //Ostream operator overloading, to replace ToString()

// MODIFIERS:

        void Radius(const double &radius);                  //Radius function taking as argument a reference value 'radius'.
        void CenterPoint(const double &center);
        double Diameter() const;                            //Function calculating diameter of circle
        double Area() const;                                //Function calculating area of circle
        double Circumference() const;                       //Function calculating circumference of circle

};

#endif