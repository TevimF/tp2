#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <iostream>
#include "MinHeap.hpp"

using namespace std;

class PriorityQueue {
    int* arr;
    int capacity;
    int size;
public:
    // Constructor
    PriorityQueue(int capacidade);
    // Destructor
    ~PriorityQueue();
    // Insert
    void insert(int data);
    // Heapify Up
    void heapifyUp(int index);
    // Extract Max
    int extractMax();
    // Heapify Down
    void heapifyDown(int index);
};

#endif  // PRIORITYQUEUE_HPP
