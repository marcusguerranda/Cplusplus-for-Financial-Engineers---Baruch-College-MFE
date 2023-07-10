// Circle.hpp 
// Purpose: Header file of circles defined in 2 dimensions. Contains constructor, destructor, copy assignment, setters, 
//          and getters such as calculating the area or circumference of circle
// Modification dates: 11/27/2022 


#ifndef Circle_hpp
#define Circle_hpp
            
#include "Point.hpp"            //Point header file
#include "Line.hpp"             //Line header file  
#include "Shape.hpp"	        //Shape header file


namespace AndrewGuerrand
{
        namespace CAD
        {
                class Circle: public Shape
                {

                //DATA MEMBERS

                private:
                        
                        Point m_center;         //Center point
                        double m_radius;        //Radius

                public:

                // CONSTRUCTORS AND DESTRUCTORS

                        Circle();                                           //Default constructor
                        Circle(const Point& center, const double& radius);  //Constructor for circle object taking radius and center point coordinates
                        Circle(const Circle& source);                            //Copy constructor of another circle object
                        Circle& operator = (const Circle& source);               //Assignment operator
                        virtual ~Circle();                                  //Default destructor

                // SELECTORS:

                        double const &Radius() const;                       //Radius of a said circle
                        Point const &CenterPoint() const;                   //Centerpoint

                        friend std::ostream &operator << (std::ostream& os, const Circle& source);   //Ostream operator overloading, to replace ToString()
                        std::string ToString() const;                                           //ToString() function to print description about circle

                // MODIFIERS:

                        void Radius(const double& radius);                  //Radius function taking as argument a reference value 'radius'.
                        void CenterPoint(const double& center);
                        double Diameter() const;                            //Function calculating diameter of circle
                        double Area() const;                                //Function calculating area of circle
                        double Circumference() const;                       //Function calculating circumference of circle

                };
        }
}                

#endif