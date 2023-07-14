// Array.hpp 
// Purpose: Header file of array class using templates
//          This is an extension of previous exercises, using namespaces, const references, canonical header file principles and more.
// Modification dates: 12/7/2022 

#ifndef Array_hpp
#define Array_hpp

namespace AndrewGuerrand
{
    namespace Containers
    {

        template<typename T>
        class Array                               //Template class Array<T>
        {
        private:

        //DATA MEMBERS:

            T* m_data;                            //Data member for a dynamic C array of T* objects
            int m_size;                           //Data member for the size of the array


        public:

        // CONSTRUCTOR AND DESTRUCTOR

            Array();                                                //Default constructor
            Array(const int& given_size);                           //Constructor with size argument; implementation will allocate the number of elements specified by the size input argument
            Array(const Array<T>& source);                          //Copy constructor for arrays
            Array<T>& operator = (const Array<T>& source);          //Assignment operator
            virtual ~Array();                                       //Destructor

        // SELECTORS/ GETTERS
            
            int const& Size() const;                                    //Function that returns the size of the array, using const reference
            const T& GetElement(int index) const;                       //Getter function. When the index is out of bounds, return the first element. Using const reference
            T& operator [] (int index);                                 //Square bracket operator, returning a reference so the [] operator can be used for reading and writing elements
            const T& operator [] (int index) const;                     //const square bracket operator --> see explanation in Array.cpp


        // MODIFIERS/SETTERS

            void SetElement(const T& t, int p_index);                   //Functions that sets an element
        };
    }
}

#ifndef Array_cpp                                                       // Array_cpp scope
#include "Array.cpp"
#endif



#endif      //Array_hpp scope

/*          Tip: by placing the following code at the end of the array header file (see line 50 to 52 in this source file), but before the header 
            file’s #endif, the client can keep including the header file for template classes instead of the 
            source file. Can you explain how this works?:


To my understanding, this 'issue' is not so much a matter required by the standard itself, but rather by the compilers we use.
With a normal function, the code would be defined in a header file, and implemented in a source file. This source file would then be subsequently written out to an object file, 
created when compiling that function.

However with a template function, the compiler cannot compile it into an object code for any object type ahead of time. That said, the implementation of the template class
needs to be known at compile-time and not at link-time. In order to do so, we include the .cpp file into the .hpp file, and include the .hpp file in main.cpp. Guards are used 
to avoid defining the template twice.

*/