//Exercise 4.2 a h1
//
//Purpose: We, in this exercise, use templates to create an array of points, rather than the overloaded functions we had used before, which could only store Point objects.
//         
//Modification date: 12/7/2022


#include <iostream>

#include "Array.cpp"        // Include the source file rather than the header file. We use #ifndef/#define/#endif statements to avoid multiple defining of the same template 
#include "Point.hpp"                        //Point class header file
using namespace AndrewGuerrand::Containers; //Accessing namespace AndrewGuerrand::Containers essential if one wants to access Array template class and Array Exception
using namespace AndrewGuerrand::CAD;        //Accessng Andrew::CAD namespace

int main()
{
    
    int size = 3;       
    Array<Point> points(size);                  //Creating array of 3 point objects

    std::cout << "Array of point objects created with size:" << points.Size() << std::endl;     //Printing out size of array we have defined using Size() function

    points.SetElement(Point(23.1, 12.2), 1);            //Using SetElement function with a given point and setting it to second index
    
    Point point1(2.1, 10.3);                            //Using overloaded point constructor and assigning to first index
    points[0] = point1;                                  

    for (int i=0; i != size; i++ )
    {
        std::cout << points[i] << std::endl;    //Printing out each point within the array that was defined with a template Array
    }

    std::cout << "OR WE CAN USE GetElement FUNCTION!" << std::endl;

    std:: cout << "Element 1 in the points Array is: " << points.GetElement(0) << std::endl;        //Printing point objects using GetElement() function
    std:: cout << "Element 2 in the points Array is: " << points.GetElement(1) << std::endl;
    std:: cout << "Element 3 in the points Array is: " << points.GetElement(2) << std::endl;

    try
    {
        points[0] = points[1];                  //Using = operator
        std::cout << points[0] << std::endl;  //Now first and second index contain the same point object

        std::cout << points[14] << std::endl;    //Should catch an error --> out of bounds
    }
     catch(ArrayException& exception)           //Polymorphic net
    {
        std::cout << exception.GetMessage()  << std::endl;
    } 
    catch(...)
    {
        std::cout << " User, ERROR MESSAGE from catch(...) !" << std::endl;
    }




    return 0;
}











