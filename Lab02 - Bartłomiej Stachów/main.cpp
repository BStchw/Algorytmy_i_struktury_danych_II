#include <iostream>
#include <stdlib.h>
#include "heap.hpp"

using namespace std;


int main( int argc, char * argv[] ) {

    PQHeap<string> queue;
    string data;
    int value;

    if(argc%2 == 0)
    {
        cout<<"Not enough arguments"<<endl;
    }
    else
    {

        for(int i = 1; i < argc; i++)
        {
            if(i%2 != 0)
            {
                data = argv[i];
            }
            else if(i%2 == 0)
            {
                value = stoi(argv[i]);
                queue.InsertElement(value, data);
            }
        }

        
    }
    int size;
    size = queue.getSize(); 
    //for(int i=0; i<queue.getSize(); i++)
    for(int i=0; i<size; i++)
    {
        queue.pop();
        cout << " ";

    }
    cout << endl;

    return 0;
}