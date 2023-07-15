// Point.hpp 
// Purpose: Header file of points defined in 2 dimensions. Contains constructor, destructor, copy assignment, assignment overloadings, calculating distance functions
// Modification dates: 11/28/2022 


#ifndef Point_hpp
#define Point_hpp

#include "Shape.hpp"    //Shape header file, abstract class


namespace AndrewGuerrand
{
    namespace CAD
    {
            class Point : public Shape	                    
            {
            private:

            //DATA MEMBERS
                
                double m_x;	                                //x-coordinate
                double m_y;	                                //y-coordinate

            public:		

            //CONSTRUCTORS AND DESTRUCTOR	
                
                Point();                                                    //Default constructor
                Point(double newyval, double newxval);                      //Overloaded constructor, instead of using SetX and SetY functions
                Point (const Point& source);                                //Copy constructor
                Point& operator = (const Point& source);                    //Assignment operator
                virtual ~Point();                                           //Destructor

            //SELECTORS
                
                double const& X() const;                                    //Functions to get the value of X and Y, making the getter function a const function
                double const& Y() const;	
                virtual void Draw() const;                                  //Method to simulate drawing by printing out some defined text 

            //MODIFIERS
                
                void X(double newxval);                                                     //Functions to set (new) values for X and Y 
                void Y(double newyval);	

                virtual std::string ToString() const;	                                    //Function ToString() to return a string description of the point.
                friend  std::ostream& operator << (std::ostream& os, const Point& source);  //Ostream operator overloading, to replace ToString()

                double Distance() const;                                                //Declaring a function that calculates the distance betwen a point and its origin
                double Distance(const Point &source) const;                             //Declaring a function that calculates the distance betwen two points, using call by reference

            //OPERATOR OVERLOADING

                Point operator - () const;                      //Negate the coordinates
                Point operator * (double factor) const ;        //Scale the coordinates
                Point operator + (const Point& source) const;   //Add coordinates
                bool operator == (const Point& source) ;        //Equally compare operator
                Point &operator *= (double factor);             //Scale the coordinates and assignment    
            }; 
    }
}

#endif