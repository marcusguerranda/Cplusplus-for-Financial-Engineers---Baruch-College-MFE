//Exercise 4.2 b h4
//
//Purpose: In this particular exercise, we focus especially on the implementation of the template class Stack.
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

//EXPLANATION FOR THIS EXERCISE: There were multiple explanations given on quantnet's forum in regard to the implementation of Push() and Pop(), and how this affects 
//                               the current index. My understanding, and what seems to me most logical is the following: when pushing an element, it stores the said-element
//                               at the current index, and then increments the current index by one. Two cases: either the array is full, and pushing an additional element triggers
//                               an exception, or the array is not full.In either case, the m_current data, which is a data member taking for value the current index in the array,
//                               will always be equal to the number of elements in the array. As such, this complements the 'architecture' of the Pop() function, which decrements,
//                               and only then removes the said element. 

int main()
{
//Initializing stack of doubles and points (default size being 24)
    Stack<double> stack_double1; 
    Stack<Point> stack_points1;             

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
    catch(ArrayException& exception)
    {
        
        std::cout << exception.GetMessage() << std::endl;
    }
    catch(...)
    {
        std::cout << "User, an unhandled exception has been encountered... Mr Machine doesn't know what to do." << std::endl;
    }    

    std:: cout << "CURRENT:" << stack_double1.Currentindex() << std::endl;


//Testing OUTOFBOUNDSEXCEPTION after Popping 24 elements in stack_double1 and testing out popping an additional one
    try
    {   
        for(int i=0; i<25; i++)                                 //Trying to pop 25 elements (24 -> 0)
        {
            std::cout << stack_double1.Pop() << std::endl;                         
        }

        std::cout << "A plain message" << std::endl;            //WON'T print, because of OutOfBoundsException (default size of array is 24, and thus we are popping one too much)
    }   
    catch(ArrayException& exception)
    {
        std::cout << exception.GetMessage() << std::endl;
    }
    catch(...)
    {
        std::cout << "User, an unhandled exception has been encountered... Mr Machine doesn't know what to do." << std::endl;
    }
    
    std:: cout << "CURRENT:" << stack_double1.Currentindex() << std::endl;

    return 0;
}











