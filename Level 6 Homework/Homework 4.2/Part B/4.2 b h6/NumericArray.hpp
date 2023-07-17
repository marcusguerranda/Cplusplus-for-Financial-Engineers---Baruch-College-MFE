// NumericArray.cpp 
// Purpose: Header file of NumericArray class using templates
//          This is an extension of previous exercises, using namespaces, const references, canonical header file principles and more.
//          We focus in this header file, and subsequently its source file, on the implementation of derived numeric functionality files that complement the Array files 
// Modification dates: 12/9/2022 



#ifndef NumericArray_hpp
#define NumericArray_hpp

#include "Array.hpp"


namespace AndrewGuerrand
{
    namespace Containers
    {

        template<typename T>
        class NumericArray : public Array<T>                        //Template class NumericArray<T>
        {
            private:
                //None
            public:

        //CONSTRUCTORS AND DESTRUCTOR

            NumericArray();                                         //Default constructor          
            NumericArray(const int& given_size);                    //Overloaded constructor taking given_size as argument for the size of the array 
            NumericArray(const NumericArray<T>& source);            //Copy constructor
            virtual ~NumericArray();                                //Virtual destructor


        //GETTERS/MODIFIERS

            NumericArray<T>& operator = (const NumericArray<T>& source);        //Assignment operator
            NumericArray<T> operator + (const NumericArray<T>& source) const;   //Adding elements of two numeric arrays together
            NumericArray<T> operator * (T factor) const ;                       //Scaling elements of the numeric array by a given factor
            
            T DotProduct (const NumericArray<T>& source) const;                 //Dot product function to calculate the dot product
        };
    }
}

#ifndef NumericArray_cpp
#include "NumericArray.cpp"
#endif                                                              //Numeric_Array_cpp scope



#endif                                                              //NumericArray_hpp scope

