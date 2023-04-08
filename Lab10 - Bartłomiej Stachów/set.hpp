// set.hpp

#ifndef SET_H
#define SET_H

#include <iostream>
#include <cassert>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iterator>

template <typename T>
class Set {
public:
    std::vector<T> set;

    ~Set() { set.clear(); }
    
    int size() const { return set.size(); }


    void insert(const T& item) {
        if ( (std::find(set.begin(), set.end(), item) != set.end()) == false)
        {
            set.push_back(item);
        }
    }

    void pop(const T& item) {
        std::vector<int>::iterator it_set;
        it_set = find(set.begin(), set.end(), item);
        set.erase(it_set);

    }

    bool isMember(const T& item) {
        if (std::find(set.begin(), set.end(), item) != set.end())
        {
            return true;
        }
        else {
            return false;
        }
    }
    bool begin(const T& item) {
        std::vector<int>::iterator it_set = set.begin();
        if (*it_set == item)
        {
            return true;
        }
        else {
            return false;
        }
    }


    void clear() { set.clear(); }
    void display() {
        std::vector<int>::iterator it_set = set.begin();
        for(; it_set != set.end(); it_set++) {
            std::cout <<* it_set << " ";
        }
    }

    std::vector<T> unionn(Set set2) { 
        std::vector<int>::iterator it_set2 = set2.set.begin();
        T element;

        for(; it_set2 != set2.set.end(); it_set2++) {
            element = *it_set2;
            if(isMember(element) == false)
            {
                insert(element);
            }

        }
    return set;    
    }

    std::vector<T> difference(Set set2) {
       std::vector<int>::iterator it_set2 = set2.set.begin();
        T element;

        Set<T> c;
        c.set=set;

        for(; it_set2 != set2.set.end(); it_set2++) {
            element = *it_set2;
            if(isMember(element)==true)
            {
                c.pop(element);
            }
            

        }
        return c.set;
    }

    std::vector<T> intersection(Set set2) {
        std::vector<int>::iterator it_set2 = set2.set.begin();

        T element;

        Set<T> c;
        c.set = set;

        for(; it_set2 != set2.set.end(); it_set2++) {
            element = *it_set2;
            if(c.isMember(element)==false)
            {
                    c.pop(element);
            }
            

        }
        return c.set;
    }

    void popAll(Set set2) {
       std::vector<int>::iterator it_set2 = set2.set.begin();
        T element;

        for(; it_set2 != set2.set.end(); it_set2++) {
            element = *it_set2;
            if(isMember(element)==true)
            {
                if(set2.isMember(element)==true)
                {
                    pop(element);
                }
            }
            

        }
    }

};



#endif

// EOF