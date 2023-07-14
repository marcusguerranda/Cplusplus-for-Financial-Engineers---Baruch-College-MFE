//Exercise 4.2 b h1
//
//Purpose: We, in this exercise, use templates to create an array of points, rather than the overloaded functions we had used before, which could only store Point objects.
//         We focus here most specificaly on how 'static' impacts the array default size
//Modification date: 12/9/2022


#include <iostream>

#include "Array.cpp"        // Include the source file rather than the header file. We use #ifndef/#define/#endif statements to avoid multiple defining of the same template 
#include "Point.hpp"                        //Point class header file
using namespace AndrewGuerrand::Containers; //Accessing namespace AndrewGuerrand::Containers essential if one wants to access Array template class and Array Exception
using namespace AndrewGuerrand::CAD;        //Accessng Andrew::CAD namespace

int main()
{
    
    Array<int> intArray1;
    Array<int> intArray2;
    Array<double> doubleArray;
   
    std::cout << intArray1.DefaultSize() << std::endl;      //24, given it is the default size defined in Array.cpp
    std::cout << intArray2.DefaultSize() << std::endl;      //24, given it is the default size defined in Array.cpp
    std::cout << doubleArray.DefaultSize() << std::endl;    //24, given it is the default size defined in Array.cpp
    
    intArray1.DefaultSize(15);                              //Setting the default size of Array<int> to 15
    
    std::cout << intArray1.DefaultSize() << std::endl;      //15
    std::cout << intArray2.DefaultSize() << std::endl;      //15
    std::cout << doubleArray.DefaultSize() << std::endl;    //24



/* 
    ANSWER: The first thing I notice is that doubleArray.DefaultSize() remains at 24 (default size) whereas other Array<int> templates arrays have their default size 
            changed and set to 15. One can obviously point out the fact that Array<int> and Array<double> are different templates, and that thus, a modified default size on one
            does not affect the other array.

            The second observation is that when changing  intArray1.DefaultSize() to 15, the getter function for intArray2 also outputs 15. 
            This is due to the fact that we are dealing with static member variables, and inevitably that m_default_size will remain specific to Array<type> that is specified.
            In plain terms, it appears that the m_default_size is shared among all Array<int> instances for example, but not with Array<double> for example.

*/


    return 0;
}











