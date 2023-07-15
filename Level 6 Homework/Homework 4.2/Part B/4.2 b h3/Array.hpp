// Array.hpp 
// Purpose: Header file of array class using templates
//          This is an extension of previous exercises, using namespaces, const references, canonical header file principles and more.
//          We focus here most specificaly on how 'static' impacts the array default size
// Modification dates: 12/9/2022 

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

            T* m_data;                                  //Data member for a dynamic C array of T* objects
            int m_size;                                 //Data member for the size of the array,
            static unsigned int m_default_size;         //Data member for the default size of the array, STATIC


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
            static unsigned int DefaultSize();                          //Getter function to get the default size of the array
            T& operator [] (int index);                                 //Square bracket operator, returning a reference so the [] operator can be used for reading and writing elements
            const T& operator [] (int index) const;                     //const square bracket operator --> see explanation in Array.cpp


        // MODIFIERS/SETTERS

            void SetElement(const T& t, int p_index);                   //Setter function that sets an element in the array
            static void DefaultSize(unsigned int size_default_setter);  //Static setter function to set default size of array
        };
    }
}

#ifndef Array_cpp                                                       // Array_cpp scope
#include "Array.cpp"
#endif



#endif      //Array_hpp scope

