//Exercise: STL h1
//
//Purpose: Working with different STL containers 
//
//Last modified: 12/19/2022

#include <list>             //STL header file for lists
#include <vector>           //STL header file for vectors
#include <map>              //STL header file for maps
#include <iterator>         //st::ostream_iterator
#include <iostream>

int main()
{

//Creating a LIST of doubles and adding some data. 

    std::list<double> list_double1; 
    list_double1.push_front(3.2);       //Pushing elements from the front using STL main member function
    list_double1.push_front(0.07);

    list_double1.push_back(11.11);      //Pushing elements from the back using STL main member function
    list_double1.push_back(22.22);

//Using front() function to access firt element of LIST
    
    std::cout << "The first element of the list is: " << list_double1.front() << std::endl;

//Using back() function to access last element of LIST

    std::cout << "Using back(), the last element of the list is: " << list_double1.back() << std::endl;

//Printing SIZE of list:

    std::cout << "The current size of the list is: " << list_double1.size() << std::endl;

//Popping some elements using pop_front() and pop_back()

    //We know first element in list is 333.333. When using pop.front(), the first element should now be 3.2
    list_double1.pop_front();
    std::cout << "The first element of the list is NOW: " << list_double1.front() << std::endl;

    list_double1.pop_back();
    std::cout << "The last element of the list is NOW: " << list_double1.back() << std::endl;

//Sorting the list by using sort(), and printing using ostream_iterator
    list_double1.sort();
    std::copy(list_double1.begin(), list_double1.end(), std::ostream_iterator<double>(std::cout, " ")); std::cout << std::endl;


//Reversing the list by using reverse(), and printing using ostreamm_iterator
    list_double1.reverse();
    std::copy(list_double1.begin(), list_double1.end(), std::ostream_iterator<double>(std::cout, " ")); std::cout << std::endl;

//////////////////////////////////////////

//Creating a VECTOR of doubles and adding some data; using reserve too
    
    std::vector<double> vector_double1;
    std::cout << "CAPACITY initial size: " << vector_double1.capacity() << std::endl;
    vector_double1.reserve(10);             //Reserving space for 10 elements

    std::cout << "The size of the vector is " << vector_double1.size() << ", and its capacity is " << vector_double1.capacity() << std::endl;
    
//NOTE FOR SELF: Obviously, and by nature of the vector, the size of the vector is 0 at first as no elements have been added yet.
//               Once I reserve capacity for 10 elements, capacity is 10 but the size remains 0, as I have not pushed in elements.
//               Pushing 15 elements in, the capacity will readjust and will change to a new larger one.
    
    for (int i = 0; i<15; i++)
    {
        vector_double1.push_back(i*0.32);   //15 elements in defined vector std::vector<double> vector1; 
    }

    std::cout << "The size of the vector is " << vector_double1.size() << ", and its capacity is " << vector_double1.capacity() << std::endl;   
    //CAPACITY is now 20, when pushing 15 elements in. Vector grows.

//Using index operator to access some elements. 

    for (int i = 0; i < vector_double1.size(); i++)
    {
        std::cout << vector_double1[i] << std::endl;
    }

//Creating a MAP that maps strings to doubles

    std::map<const char*, double> perfume_prices;
    std::map<const char*, double>::iterator it;

//Filling the MAP

    perfume_prices["Sauvage"] = 109.00;             //Using [] operator
    perfume_prices["CH Men Prive"] = 145.00;
    perfume_prices["Eros"] = 96.00;
    perfume_prices["Bleu"] = 117.00;  

//Accessing elements using the square bracket operator

    it = perfume_prices.find("Bleu");
    std::cout << "The price of " << it->first << " is " << it->second << std::endl;                 //Using find() 

    it = perfume_prices.find("CH Men Prive");
    std::cout << "The price of CH Men Prive is: " << perfume_prices["CH Men Prive"] << std::endl;    //Using [] operator

    return 0;
}
