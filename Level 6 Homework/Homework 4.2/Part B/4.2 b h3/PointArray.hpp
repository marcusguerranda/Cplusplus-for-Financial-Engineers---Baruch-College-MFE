// PointArray.hpp 
// Purpose: PointArray which is derived from Array with the template argument set to Point.
//          A Length() function has also been added.
// Modification dates: 12/10/2022 


#ifndef PointArray_hpp                                      //Guards to avoid multiple definitions
#define PointArray_hpp

#include "Array.hpp"                                        //Array header file
#include "Point.hpp"                                        //Point header file
using AndrewGuerrand::CAD::Point;                           //For class Point access

namespace AndrewGuerrand
{
    namespace Containers
    {
        class PointArray : public Array<Point>              //Concrete inheritance; template argument fixed to type 'Point'
        {
        private:
            //No data members

        public:
    //CONSTRUCTORS AND DESTRUCTOR

        PointArray();                                       //Default constructor
        PointArray(const int& given_size);                  //Overloaded constructor
        PointArray(const PointArray& source);               //Copy constructor
        PointArray& operator = (const PointArray& source);  //Assignment operator
        virtual ~PointArray();                              //Destructor

    //GETTER/SELECTOR:

        double Length() const;                              //Length() function that returns the total length between the points in the array
        };
    }
}

#endif
