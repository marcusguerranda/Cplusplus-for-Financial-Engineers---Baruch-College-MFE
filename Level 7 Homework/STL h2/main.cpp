//Exercise: STL h2
//
//Purpose: Working with different STL containers, and creating a SumContainer header file to define implementations in regard to how to calculate the sum 
//         of a complete container, or between two iterators
//
//Last modified: 12/19/2022

#include "SumContainer.hpp"         //Header file which comprises of template functions to sum the complete container or between two iterators
#include <iostream>

int main()
{

//LISTS: Creating a LIST of doubles and adding some data 

    list<double> l_double1;          // Creating list
    l_double1.push_front(3.2);       //Pushing elements from the front using STL main member function
    l_double1.push_front(0.07);

    l_double1.push_back(11.11);      //Pushing elements from the back using STL main member function
    l_double1.push_back(22.22);

//Calculating sum of elements contained in the entire list container

    cout << "The sum of all double elements in l_double1 is: " << Sum(l_double1) << endl;   //Generic

//Calculating the sum of the two double elements in the middle of the list

    list<double>::const_iterator l_double1_start = ++l_double1.begin();    //Starting const iterator one past the first, or the second in the middle of the list
    list<double>::const_iterator l_double1_end = --l_double1.end();        //Ending const iterator one prior l_double1.end(), to target two elements in the middle.
    cout<< "The sum of the two elements in the middle of l_double1 is: " << Sum(l_double1_start, l_double1_end) << endl;


//VECTORS: Creating a VECTOR of doubles and adding some data

    vector<double> v_double1;       //Creating vector
    for(int i =0; i<4; i++)         //Asssigning some double values to vector
    {
        v_double1.push_back(i*3.2);
    }

//Calculating sum of elements contained in the entire vector container

    cout << "The sum of all double elements in v_double1 is: " << Sum(v_double1) << endl;   //Generic

//Calculating the sum of the double elements in the middle of the vector

    vector<double>::const_iterator v_double1_start = v_double1.begin()+1;    //Starting const iterator one past the first, or the second in the middle of the vector
    vector<double>::const_iterator v_double1_end = v_double1.end()-1;        //Ending const iterator one prior v_double1.end(), to target two elements in the middle.
    cout<< "The sum of the two elements in the middle of v_double1 is: " << Sum(v_double1_start, v_double1_end) << endl;


//MAPS: 

    map<const string, double> map1;             //Creating map
    map1["Sauvage"] = 109.00;                   //Using [] operator
    map1["CH Men Prive"] = 145.00;
    map1["Eros"] = 96.00;
    map1["Bleu"] = 117.00;  

//Calculating sum of all values in map1:
    cout << "The sum of all prices for the 4 perfumes in map1 are: "   << Sum(map1) << endl;

//Calculating the sum of CH Men Prive and Eros, and not of Sauvage and Bleu:
    map<const string, double>::const_iterator map1_begin = ++map1.begin();
    map<const string, double>::const_iterator map1_end = ++map1.end();   
    cout << "The sum of prices for CH Men Prive and Eros are, in total, of: " << Sum(map1_begin, map1_end) << endl; 

    return 0;
}
