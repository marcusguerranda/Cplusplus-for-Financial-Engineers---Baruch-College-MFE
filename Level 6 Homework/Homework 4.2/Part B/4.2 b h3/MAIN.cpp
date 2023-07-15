//Exercise 4.2 b h3
//
//Purpose: We, in this exercise, use templates to create an array of points, rather than the overloaded functions we had used before, which could only store Point objects.
//         We focus on how 'static' impacts the array default size.
//         We also created a Numeric Array template class to deal with numerical functionality, and deal with potential exceptions thrown with another derived class dealing
//         with arrays that are not the same size.
//         In this specific exercise, we define a header and source file that deals with arrays of Points: PointArray() and an associated Length() function to calculate
//         the distance of the polyline.
//Modification date: 12/10/2022


#include <iostream>
#include "PointArray.hpp"                   //PointArray header file
using namespace AndrewGuerrand::Containers; //Accessing namespace AndrewGuerrand::Containers essential if one wants to access Array template class and Array Exception
using namespace AndrewGuerrand::CAD;        //Accessng Andrew::CAD namespace


int main()
{
    try
    {
    //Creating three different arrays of points
        PointArray point_array1(24);            //Array of points with size 24, initilized with 24 default points            //OVERLOADED constructor
        PointArray point_array2;                //Array of points with default size 24, with 24 default points               //DEFAULT constructor
        
    //Testing copy constructor    
        PointArray point_array3(point_array1);  //Array of points using copy constructor, with 24 default points             //COPY constructor

        std::cout << "User, default size of the array of points should be 24. point_array 1 has size: " << point_array1.Size() << std::endl;
        std::cout << "User, point_array2 has default size, which is: " << point_array2.Size() << std::endl;
        std::cout << "User, point_array3 has the size of point_array1, which is: " << point_array2.Size() << std::endl;


    //Assigning somewhat-random values to point_array1, and point_array2, and point_array3 has been copied with 'template' point_array1. 
    //Random() value not used for now.
    for (int i = 0; i < point_array1.Size(); i++)
    {
        point_array1[i] = Point(i-2, i*0.75);           
        point_array2[i] = Point(i*2.4, i-2.3); 
    }

    //At this point, it is normal for point_array3 to have all its points equal to Point(0,0), because point_array1 has been initialized with default points.
    for (int i = 0; i < point_array1.Size(); i++)
    {
        std::cout << "Point " << i+1 << " in point array 1 is: " << point_array1[i] << std::endl; 
        std::cout << "Point " << i+1 << " in point array 2 is: " << point_array2[i] << std::endl;
        std::cout << "Point " << i+1 << " in point array 3 is: " << point_array3[i] << std::endl;      
    }
    std::cout << "" << std::endl; std::cout << "" << std::endl; // To create a bit more space in output, to read better

    //Testing ASSIGNMENT operator to make point_array1 and point_array3 equal, as such:
    //Both arrays of points should be identical.
    point_array3 = point_array1;
    for (int i = 0; i < point_array1.Size(); i++)
    {
        std::cout << "Point " << i+1 << " in point array 1 is: " << point_array1[i] << std::endl; 
        std::cout << "Point " << i+1 << " in point array 3 is: " << point_array3[i] << std::endl;      
    }

    //Ok, it works.
    std::cout << "" << std::endl; std::cout << "" << std::endl; // To create a bit more space in output, to read better

    //Testing out Length() function
    std::cout << "Length of polyline in point_array1 is: " << point_array1.Length() << std::endl;
    std::cout << "Length of polyline in point_array2 is: " << point_array2.Length() << std::endl;    
    std::cout << "Length of polyline in point_array3 is: " << point_array3.Length() << std::endl; //Should be equal to that of point_array1

    //Ok, it works.
    std::cout << "" << std::endl; std::cout << "" << std::endl; // To create a bit more space in output, to read better

    //Testing OutOfBoundsException
    std::cout<< point_array1[77] << std::endl;

    }
    catch(const ArrayException& exception)
    {   
        //Exception message from one of derived classes of ArrayException
        std::cout << exception.GetMessage() << std::endl;                                         
    }
    catch(...)
    {
        std::cout << "User, an unhandled exception has been thrown... Mr.Machine does not know what to do." << std::endl;
    }

    return 0;
}











