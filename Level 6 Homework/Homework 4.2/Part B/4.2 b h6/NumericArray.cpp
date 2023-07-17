// NumericArray.cpp 
// Purpose: Source file of NumericArray class using templates
//          This is an extension of previous exercises, using namespaces, const references, canonical header file principles and more.
//          We focus here most specificaly on how 'static' impacts the array default size
// Modification dates: 12/9/2022 


#ifndef NumericArray_cpp
#define NumericArray_cpp

#include "NumericArray.hpp"
#include "NotSameSizeException.hpp"


namespace AndrewGuerrand
{
    namespace Containers
    {
        
    //CONSTRUCTORS AND DESTRUCTOR    
        
        //Default constructor
        template <typename T>
        NumericArray<T>::NumericArray(): Array<T>()     
        {
            //std::cout << "User, DEFAULT constructor NumericArray is used" << std::endl;
        }

        //Overloaded constructor
        template <typename T>
        NumericArray<T>::NumericArray(const int& given_size): Array<T>(given_size)
        {
            //std::cout << "User, OVERLOADED constructor used in NumericArray" << std::endl;
        }

        //Copy constructor
        template <typename T>
        NumericArray<T>::NumericArray (const NumericArray<T>& source): Array<T>(source)
        {
            //std::cout << "COPY constructor in NumericArray" << std::endl;
        }

        //Virtual destructor
        template <typename T>
        NumericArray<T>::~NumericArray()
        {
            //std::cout << "User, DESTRUCTOR in NumericArray used." << std::endl;
        }


        //GETTERS/MODIFIERS

        // =operator: Assignment operator
        template <typename T>
        NumericArray<T>& NumericArray<T>::operator = (const NumericArray<T>& source)
        {
            if (this == &source)                //Check for self-assignment
            {
                return *this;
            }
            else
            {
                Array<T>::operator = (source);   //Assigning
                return *this;
            }
        }        

        // +operator: Adding elements of two numeric arrays together
        template <typename T>
        NumericArray<T> NumericArray<T>:: operator + (const NumericArray<T>& source) const
        {
            if(this->Size() != source.Size())
            {
                throw NotSameSizeException();                               //Dimensions not equal
            }
            else
            {
                NumericArray<T> new_arr(source.Size());
                for (int i=0; i < new_arr.Size(); i++)                     //For-loop to iterate through each arrays indices and sum elements into new array.
                {
                    new_arr[i] = this->GetElement(i) + source.GetElement(i);           
                }

                return new_arr;                                             //Return the new array that was created
            }
        }


        //*operator = scaling elements of the numeric array by a given factor
        template<typename T>
        NumericArray<T> NumericArray<T>:: operator * (T factor) const                
        {
            NumericArray<T> new_arr((*this).Size());

            for(int i=0; i < (*this).Size(); i++)                              //For-loop iterating through the array and scaling by factor
            {
                new_arr[i] = (*this)[i] * factor;
            }

            return new_arr;
        }
        

        //Dot product
        template <typename T>
        T NumericArray<T>::DotProduct (const NumericArray<T>& source) const                 //Dot product function to calculate the dot product
        {
            if(this->Size() != source.Size())
            {
                throw NotSameSizeException();                               //Dimensions not equal
            }
            else
            {
                T dotproduct_result(0);                                     //Initialize dot product result to 0, for now
                for (int i =0; i < source.Size(); i++)                      //Iterate through each indices for dot product operation
                {
                    dotproduct_result += (this->GetElement(i) * source.GetElement(i));
                }

                return dotproduct_result;
            }
        }
    }
}


#endif