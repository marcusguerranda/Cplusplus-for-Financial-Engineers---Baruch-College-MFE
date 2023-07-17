//Exercise 4.2 b h6
//
//Purpose: In this particular exercise, we focus especially on the implementation of the template class Stack. Here, we also change the stack class so that is uses a value template
//         argument to set the stack size.
//Modification date: 12/16/2022

/*FOR PERSONAL NOTES:
Using another class as data member is called COMPOSITION. In this case the Stack class uses 
internally an Array class. Forwarding functionality to another class is called DELEGATION. Here 
the Stack class delegates the storage of elements to the Array class.*/


#include <iostream>                         //Iostream header file 
#include "Point.hpp"                        //Point header file
#include "Stack.hpp"                        //Stach header file
using namespace AndrewGuerrand::Containers; //Accessing namespace AndrewGuerrand::Containers essential if one wants to access Array template class and Array Exception
using namespace AndrewGuerrand::CAD;        //Accessng Andrew::CAD namespace

int main()
{
//Initializing stack of doubles and points
    Stack<double, 24> stack_double1; 
    Stack<Point, 24> stack_points1;             

//Using Push() function on stack_points1 (int type) and assigning pseudo-random (not really by mathematical definition) Point objects to each index
    for(int i = 0; i < 24; i++)                     //24 being the default size of Array
    {
        stack_points1.Push(Point(i+2.1, i*3.7));
    }

    std::cout << "Pushing Points into stack array clearly works! And we have the luxury of benefiting from an additional description on each Point object." << std::endl;
    
    
//Using Push() function on stack_double1 (double type) and assigning pseudo-random (not really by mathematical definition) Point objects to each index
//Also testing for OutofBoundsException when 'Push'ing too much.
    try
    {
        for(int i = 0; i < 25; i++)                     //25 elements (0 -> 24) being one more than the default size of Array
        {
            stack_double1.Push(i*2.37);
        }
            std::cout << "A plain message to see what happens when we Push() beyong size of array." << std::endl;
    }
    catch(StackException& exception)
    {
        
        std::cout << exception.GetMessage() << std::endl;
    }
    catch(...)
    {
        std::cout << "User, an unhandled exception has been encountered... Mr Machine doesn't know what to do." << std::endl;
    }    

    std:: cout << "CURRENT:" << stack_double1.GetCurrentIndex() << std::endl;


//Testing OUTOFBOUNDSEXCEPTION after Popping 24 elements in stack_double1 and testing out popping an additional one
    try
    {   
        for(int i=0; i<25; i++)                                 //Trying to pop 25 elements (24 -> 0)
        {
            std::cout << stack_double1.Pop() << std::endl;                         
        }

        std::cout << "A plain message" << std::endl;            //WON'T print, because of OutOfBoundsException (default size of array is 24, and thus we are popping one too much)
    }   
    catch(StackException& exception)
    {
        std::cout << exception.GetMessage() << std::endl;
    }
    catch(...)
    {
        std::cout << "User, an unhandled exception has been encountered... Mr Machine doesn't know what to do." << std::endl;
    }

//Is the index at 0 when Popping too far? Yes... it is! As seen below.
    std:: cout << "CURRENT:" << stack_double1.GetCurrentIndex() << std::endl;


//Trying out ASSIGNMENT OPERATOR

    try
    {
    
    Stack<double, 24> stack_double2;        //Creating a stack of doubles with same size as stack_double1
    Stack<double, 77> stack_double3;        //Of size 77

    stack_double2 = stack_double1;          //Will work
    std::cout << "Assigning stack_double1 to stack_double2 HAS worked." << std::endl;

    //stack_double3 = stack_double1;          //Not possible! ()

    }
    catch(StackException& exception)
    {

    }
    catch(...)
    {
        std::cout << "User, an unhandled exception has been encountered... Mr Machine doesn't know what to do." << std::endl;
    }

    return 0;
}











