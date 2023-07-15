// PointArray.hpp 
// Purpose: PointArray which is derived from Array with the template argument set to Point.
//
// Modification dates: 12/10/2022 

#ifndef PointArray_cpp
#define PointArray_cpp


#include "NotSameSizeException.hpp"                         //NotSameSizeException header file
#include "PointArray.hpp"                                   //PointArray header file

namespace AndrewGuerrand
{
    namespace Containers
    {
       
    //CONSTRUCTORS AND DESTRUCTOR   
        PointArray::PointArray(): Array()                                       //Default constructor
        {
            //std::cout << "User, PointArray() DEFAULT CONSTRUCTOR used." << std::endl;
        }

        PointArray::PointArray(const int& given_size): Array(given_size)        //Overloaded constructor
        {
            //std::cout << "User, PointArray() OVERLOADED CONSTRUCTOR used." << std::endl;
        }

        PointArray::PointArray(const PointArray& source): Array(source)
        {
            //std::cout << "User, PointArray COPY CONSTRUCTOR used." << std::endl;
        }


        PointArray& PointArray::operator = (const PointArray& source)            //Assigment operator 
        {
            if (this == &source)
            {
                return *this;
            }
            else
            {
                Array<Point>::operator = (source);

            }

            return *this;
        }


        PointArray::~PointArray()                                                  //Destructor
        {
            //std::cout << "User, PointArray DESTRUCTOR has been used" << std::endl;
        }


    //GETTER/SELECTOR:

        double PointArray::Length() const                                           //Length() function that returns the total length between the points in the array
        {
            double length = 0.0;
            for (int i =0; i < ((*this).Size()-1); i++)
            {
                length += (*this)[i].Distance((*this)[i+1]);                        //Calculating distance of polyline, iterating through each point of the array
            }
            return length;
        }
            //Reason as to why I type: (*this).Size()-1 is because at the last index, we cannot calculate the distance between Point of the last index and the point of the index
            //after that, because there are no point that exists. Thus, when reaching the last index, no additional calculation is performed.
            //This also tackles the issue of calculating the distance when there is only one point in the array. If such is the case, the array is of size 1, and thus no distance
            //calculation is performed.
    }
}

#endif