#ifndef MINHEAP_HPP
#define MINHEAP_HPP

#include <iostream>

using namespace std;
class MinHeap {
    int* arr;
    int capacity;
    int size;
public:
    // Constructor
    MinHeap(int capacity);
    // Destructor
    ~MinHeap();
    // Insert
    void insert(int data);
    // Heapify Up
    void heapifyUp(int index);
    // Extract Min
    int extractMin();
    // Heapify Down
    void heapifyDown(int index);
    // Print
    void print();
};

#endif // MINHEAP_HPP