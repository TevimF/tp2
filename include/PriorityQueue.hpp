#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

#include <iostream>
#include "MinHeap.hpp"
#include <utility> // For std::pair

class PriorityQueue {
    std::pair<int, float>* arr; // Array of (node, priority)
    int capacity;
    int size;
public:
    PriorityQueue(int capacidade);
    ~PriorityQueue();
    void insert(int node, float priority);
    int extractMin();
    void heapifyUp(int index);
    void heapifyDown(int index);
    int getSize();
    int parent(int index);
    int leftChild(int index);
    int rightChild(int index);
};

#endif  // PRIORITYQUEUE_HPP
