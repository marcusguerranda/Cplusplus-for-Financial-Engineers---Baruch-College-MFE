// main.cpp 
// Purposes: Dynamically creating objects, using pointers, arrays of objects, and arrays of pointers.
// Modification dates: 11/22/2022 


#include "Array.hpp"			//Including header file for Array class
#include "Point.hpp"
#include <iostream>

int main()
{
	
//CREATE AN ARRAY OF POINT POINTERS WITH 3 ELEMENTS ON THE HEAP

	Point point1(23.0, 12.0);														//Overloaded constructor with two arguments
	Point point2; 																	//Default constructor, values of 0.0 and 0.0
	Point point3(2.0);																//Explicit constructor
	
	Array array1(20);																//Constructing temporary array on the heap with size of 20
	std::cout << "Size of array 1 is:" << array1.Size() << std::endl;				//Size of the array 1 
	array1.SetElement(point1,0);													//Allocating point 1 to first slot in array
	array1.SetElement(point2,1);													//Allocating point 2 to second slot in array
	array1.SetElement(point3,2);													//Allocating point 3 to third slot in array

	Array array2(20);																//Creating a second array
	array2 = array1;																//Assignment operator

	std::cout<< "Third element in array 2 is: " << array2.GetElement(2) << std::endl;//Should be Point 3(2.0, 2.0), as per the explicit constructor and one inputted value.
	std::cout << array1[1] <<std::endl;												//Square bracket operator referring to point 2 on index 1, which is the default point(0,0)
	
	return 0;


}