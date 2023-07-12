// Line.hpp 
// Purpose: Header file of lines defined in 2 dimensions. Contains constructor, destructor, copy assignment, setters, and getters
// Modification dates: 11/28/2022 


#ifndef Line_hpp
#define Line_hpp
             
#include "Point.hpp"            //Incuding Point header file 
#include "Shape.hpp"	//Header file that contains declarations for Shape class


namespace AndrewGuerrand
{
        namespace CAD
        {
                class Line : public Shape
                {
                public:

                //DATA MEMBERS
                        Point p_starting;       //Starting point of the line
                        Point p_ending;         //Ending point of the line

                //CONSTRUCTORS AND DESTRUCTORS

                        Line();                                                 //Defaut constructor
                        Line(const Point& starting, const Point& ending);       //Constructor with start and end point, using const references to inputted points p1 and p2
                        Line(const Line& source);                               //Copy constructor of a line
                        Line& operator = (const Line& source);                  //Assignment operator
                        virtual ~Line();                                        //Destructor

                //SELECTORS

                        const Point& P1() const;                                //Getter function for start point
                        const Point& P2() const;                                //Getter function for end point 

                        virtual std::string ToString() const;                                        //ToString() function to print description about the line
                        friend std::ostream& operator << (std::ostream& os, const Line& source);     //Ostream operator overloading, to replace ToString()

                        virtual void Draw() const;                              //Method to simulate drawing by printing out some defined text

                //MODIFIERS

                        void P1(const Point& starting);                         //Setter function for start point
                        void P2(const Point& ending);                           //Setter function for ending point

                        double Length() const;                                  // Function calculating the distance between two points

                };
        }
}
#endif


