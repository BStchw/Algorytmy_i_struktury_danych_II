// heap.hpp

#ifndef HEAP_H
#define HEAP_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <stdlib.h>
#include <utility>
#include <string>
#include <cstring>




template <typename T>
class PQHeap {
private:
    const static int MAX_SIZE = 15;
    std::pair<int, T> heap[MAX_SIZE];

public:

    int size;
    PQHeap() {
        size = 0;
    }

    static int parent(int i) {
        return (i - 1) / 2;
    }

    static int leftChild(int i) {
        return 2*i + 1;
    }

    static int rightChild(int i) {
        return 2*i + 2;
    }


    static void swap(T *x, T *y) {
        T temp = *x;
        *x = *y;
        *y = temp;
    }

    int getSize() {
        return size;
    }

    int getMaxpriority() {
        return heap[0].first;
    }

    void InsertElement(int value, T data) {
        if (size >= MAX_SIZE) {
            std::cout<<"The heap is full. Cannot insert"<<std::endl;
            return;
        }

        heap[size].first = value;
        heap[size].second = data;        
        size = size + 1;


        int i = size - 1;
        while (i != 0 && heap[PQHeap::parent(i)].first < heap[i].first) {
            PQHeap<int>::swap(&heap[PQHeap::parent(i)].first, &heap[i].first);
            PQHeap<T>::swap(&heap[PQHeap::parent(i)].second, &heap[i].second);

            i = PQHeap::parent(i);
        }
    }

    void maxHeapify(int i){
        int left = PQHeap::leftChild(i);

        int right = PQHeap::rightChild(i);

        int largest = i;

        if (left <= size && heap[left].first > heap[largest].first) {
            largest = left;
        }

        if (right <= size && heap[right].first > heap[largest].first) {
            largest = right;
        }

        if (largest != i) {
            int temp = heap[i].first;
            heap[i].first = heap[largest].first;
            heap[largest].first = temp;
            maxHeapify(largest);
        }

    }


    int GetMaxPriority() {
        return heap[0];
    }

    int pop() {
        int maxItem = heap[0].first;
        std::cout << heap[0].second;

        heap[0].first = heap[size - 1].first;
        heap[0].second = heap[size - 1].second;

        size = size - 1;

        maxHeapify(0);

        return maxItem;
    }

    void printQueue() {
        for (int i = 0; i < size; i++) {
            std::cout << heap[i].first << std::endl;
            std::cout << heap[i].second << std::endl;

        }
        std::cout<<std::endl;
    }
};

#endif
