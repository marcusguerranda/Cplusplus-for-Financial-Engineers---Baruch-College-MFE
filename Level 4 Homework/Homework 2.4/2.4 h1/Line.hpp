// Line.hpp 
// Purpose: Header file of lines defined in 2 dimensions
// Modification dates: 11/21/2022 


#ifndef Line_hpp
#define Line_hpp

#include <sstream>              //C++ stream buffering 
#include "Point.hpp"            //Incuding Point header file 
#include <iostream>

class Line
{
public:

//DATA MEMBERS
        Point p_starting;       //Starting point of the line
        Point p_ending;         //Ending point of the line

//CONSTRUCTORS AND DESTRUCTORS

        Line();                                                 //Defaut constructor
        Line(const Point &starting, const Point &ending);       //Constructor with start and end point, using const references to inputted points p1 and p2
        Line(const Line &l);                                    //Copy constructor of a line
        Line& operator = (const Line &l);                       //Assignment operator
        ~Line();                                                //Destructor

//SELECTORS

        const Point& P1() const;                        //Getter function for start point
        const Point& P2() const;                        //Getter function for end point 

//MODIFIERS

        void P1(const Point &starting);                         //Setter function for start point
        void P2(const Point &ending);                           //Setter function for ending point

        std::string ToString();                                 //ToString to print description about the line

        double Length() const;                                  // Function calculating the distance between two points

};

#endif