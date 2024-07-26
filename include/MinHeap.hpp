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
    // Empilhar
    void heapifyUp(int index);
    // Pegar o menor valor
    int extractMin();
    // Desempilhar
    void heapifyDown(int index);
    // Print
    void print();
    // Size
    int getSize();
};

#endif // MINHEAP_HPP