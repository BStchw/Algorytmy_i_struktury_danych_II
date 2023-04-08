#include <iostream>
#include <cassert>
#include <stdio.h>
#include "set.hpp"

using namespace std;
int main ()
{
    Set<int> set1;
    Set<int> set2;


    set1.insert(2);
    set1.insert(5);
    set1.insert(8);
    set1.insert(6);

    set2.insert(4);
    set2.insert(3);
    set2.insert(5);
    set2.insert(8);

    cout << "Set1: " << endl;
    set1.display();

    cout << endl << "Set2: " << endl;
    set2.display(); 


    cout << endl << "Union: " << endl; 
    Set<int> set3;
    set3.set = set1.unionn(set2);
    set3.display();


    cout << endl << "Difference: " << endl;
    Set<int> set4;
    set4.set = set1.difference(set2);
    set4.display();

    cout << endl << "Intersection: " << endl;
    Set<int> set5;
    set5.set = set1.intersection(set2);
    set5.display();


    cout << endl << "popAll: " << endl;
    set1.popAll(set2);
    set1.display();
    cout << endl;
  
  

    return 0;
}