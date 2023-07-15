//Exercise 4.2 b h2
//
//Purpose: We, in this exercise, use templates to create an array of points, rather than the overloaded functions we had used before, which could only store Point objects.
//         We focus here most specificaly on how 'static' impacts the array default size.
//         We also created a Numeric Array template class to deal with numerical functionality, and deal with potential exceptions thrown with another derived class dealing
//         with arrays that are not the same size.
//Modification date: 12/9/2022


#include <iostream>
#include "NumericArray.hpp"                 //Numeric array header file to deal with numerical functionality; derived from template class Array
#include "Array.hpp"                        //Array header file
#include "ArrayException.hpp"               //ArrayException header file
#include "Point.hpp"                        //Point class header file
using namespace AndrewGuerrand::Containers; //Accessing namespace AndrewGuerrand::Containers essential if one wants to access Array template class and Array Exception
using namespace AndrewGuerrand::CAD;        //Accessng Andrew::CAD namespace


/*        Change the main program to test the numeric arra 
          --> I have tested most of the different functions that has come to my mind.


1. What assumptions do you make about the type used as template argument? 

   We assume that the type used as template argument is a numeric data type. 
   That is why when we perform, for example, a dot product on numeric arrays of points, it fails. Points are not numeric types...

2. Can you create a numeric array with Point objects?

   Yes. But as mentioned previously, operations on this numeric array of points cannot be performed because numeric operations performed on Point objects
   (*, DotProduct, etc.) will lead to errors. We would need to create a new derived class PointArray which is fixed to specifically 'Point' as a data type.

*/

int main()
{
    try
    {

    //Default constructor testing   
        NumericArray<int> array1;                                                                  
        NumericArray<int> array2;


    //Testing Size() function and checking for the DefaultSize (which is defined to be 24)
        std::cout << "User, your first array is of size: " << array1.Size() << std::endl;            //Size() function
        std::cout << "The default size for the array is: " << array2.DefaultSize() << std::endl;     //DefaultSize() function
        

    //Values created in array1 and array2 using + and *    
        for(int i=0; i< array1.Size(); i++) //Since array1 and array2 are of the same size
        {
            array1[i] = (i+3);                                                                     
            array2[i] = (i*2);
        }


    //Printing out each value in array 1 
        for(int i=0; i< array1.Size(); i++)                                                          
        {
            std:: cout << "For array 1, index " << i << " is equal to: " << array1[i] << std::endl;
        }


    //Printing out each value in array 2   
        for(int i=0; i< array2.Size(); i++)                                                         
        {
            std:: cout << "For array 2, index " << i << " is equal to: " << array2[i] << std::endl;
        }
        

    //Using COPY CONSTRUCTOR    
        std::cout << "User, using COPY CONSTRUCTOR" << std::endl;
        NumericArray<int> array3(array1);                                                           
        for(int i=0; i< array3.Size(); i++)                     //Printing out each value in array 3
        {
            std:: cout << "For array 3, index " << i << " is equal to: " << array3[i] << std::endl;
        }


    //Using + OPERATOR
        std::cout << "User, testing + OPERATOR" << std::endl;
        array3 = (array1 + array2);                             //Printing out each value in array 1

        for(int i=0; i< array1.Size(); i++)                                                         
        {
            std:: cout << "For array 3 (modified), index " << i << " is equal to: " << array3[i] << std::endl;
        }


    //Using = OPERATOR
        std::cout << "User, testing = OPERATOR" << std::endl;
        NumericArray<int> array4 = array3;                                                          
        for(int i=0; i< array4.Size(); i++)         //Printing out each value in copied array4
        {
            std:: cout << "For array 4, index " << i << " is equal to: " << array4[i] << std::endl;
        }        


    //Using * OPERATOR
        std::cout << "User, using * OPERATOR" << std::endl;
    
        array2 = (array2*2.0);                                                                      
        for(int i=0; i< array2.Size(); i++)          //Using * OPERATOR//Printing out each value in array 1 
        {
            std:: cout << "For array 2, index " << i << " is equal to: " << array2[i] << std::endl;
        }
    

    //Testing DOT PRODUCT
        //Array 4 and array 3 are of the same default length.  
        std:: cout << "User, testing DOT PRODUCT." << std::endl;
        std::cout << array4.DotProduct(array3) << std::endl;


    //Testing OutOfBoundsException    
        std::cout << array4[24] << std::endl;           //Will lead to exception 

    }
    catch(const ArrayException& exception)
    {
        std::cout << exception.GetMessage() << std::endl;                                           //Exception message from one of derived classes of ArrayException
    }
    catch(...)
    {
        std::cout << "User, an unhandled exception has been thrown... Mr.Machine does not know what to do." << std::endl;
    }
    

    try
    {
        NumericArray<double> double1(2);
        NumericArray<double> double2(4);

    //Testing out NotSameSizeError

        double1 = (double1 + double2);

    }
    catch(const ArrayException& exception)
    {
        std::cout << exception.GetMessage() << std::endl;                                           //Exception message from one of derived classes of ArrayException
    }
    catch(...)
    {
        std::cout << "User, an unhandled exception has been thrown... Mr.Machine does not know what to do." << std::endl;
    }
    


    try
    {
        //Testing point objects with some previously seen operations, but basically playing around with types used as template arguments.

        NumericArray<Point> point_arr1;                                                             //Creating an array of default size with objects points
        NumericArray<Point> point_arr2(42);                                                         //Creating an array of size 42

        //point_arr1 = point_arr1 * 2.0;                                                            //xxxxxx -- see explanation above
        //point_arr2 = point_arr1 + point_arr2;                                                     //xxxxxx -- see explanation above
        //point_arr2.DotProduct(point_arr2);                                                        //xxxxxx -- see explanation above
    }
    catch(const ArrayException& exception)
    {
        std::cout << exception.GetMessage() << std::endl;                                           //Exception message from one of derived classes of ArrayException
    }
    catch(...)
    {
        std::cout << "User, an unhandled exception has been thrown... Mr.Machine does not know what to do." << std::endl;
    }


    return 0;
}











