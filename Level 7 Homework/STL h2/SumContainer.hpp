//SumContainer.hpp
//
//Purpose: Header file for Sum() template function
//
//Last modified: 12/20/2022


#ifndef SumContainer_hpp
#define SumContainer_hpp

#include <list>                 //Header file for lists
#include <vector>               //Header file for vectors
#include <map>                  //Header file for maps
#include <string>               //Header file for strings
using namespace std;            //using declaration

//Template function to sum elements in a given container (ex-map)
template <typename T> 
double Sum(const T& source)
{
    double sum = 0.0;
    typename T::const_iterator it;
    for(it = source.begin(); it != source.end(); it++)        //For-loop to calculates sum in container (ex-map)
    {
        //Dereference iterator to obtain value at address with (*it)
        sum += (*it);                              
    }

    return sum;
}

//Template function to sum elements in a map (this is different than another containers, since we need to iterate through keys and grab values)
//Expicit Specializatiom
template <> 
double Sum (const map <const string, double>& source)
{
    double sum = 0.0;
    map<string, double>::const_iterator it;

    for(it = source.begin(); it != source.end(); it++)          //For-loop to calculate sum of values to associated keys in given map
    {
        sum += (it)->second;
    }
    
    return sum;
}

//Template function to sum elements between two iterators in a container (ex-map)
template<typename T>
double Sum(const T& start_iterator, const T& end_iterator)      //Iterators for beginning and end of range
{
    double sum = 0.0;

    for(T it = start_iterator; it != end_iterator; it++)   
    {
        sum += (*it);
    }

    return sum;
}

//Template function to sum elements between two iterators in a map
template <>
double Sum(const map<const string, double>::const_iterator& start_iterator, const map<const string, double>::const_iterator& end_iterator)
{
    double sum = 0.0;
    map<const string, double>::const_iterator it;

    for(it = start_iterator; it!= end_iterator; it++)
    {
        sum += it->second;
    }

    return sum;
}

#endif  //Sum_hpp




