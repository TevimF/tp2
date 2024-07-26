#include "../include/PriorityQueue.hpp"

// Constructor
PriorityQueue::PriorityQueue(int capacidade) : capacity(capacidade), size(0) {
    arr = new std::pair<int, float>[capacity];
}
// Destructor
PriorityQueue::~PriorityQueue() {
    delete[] arr;
}
// Insert
void PriorityQueue::insert(int node, float priority) {
    if (size >= capacity) {
        // Handle capacity overflow
        return;
    }
    arr[size] = std::make_pair(node, priority);
    heapifyUp(size);
    size++;
}
// Heapify Up
void PriorityQueue::heapifyUp(int index) {
    while (index > 0 && arr[parent(index)].second > arr[index].second) {
        std::swap(arr[parent(index)], arr[index]);
        index = parent(index);
    }
}
// Extract Max
int PriorityQueue::extractMin() {
    if (size <= 0) return -1;
    int minNode = arr[0].first;
    arr[0] = arr[size - 1];
    size--;
    heapifyDown(0);
    return minNode;
}
// Heapify Down
void PriorityQueue::heapifyDown(int index) {
    int smallest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    if (left < size && arr[left].second < arr[smallest].second) {
        smallest = left;
    }

    if (right < size && arr[right].second < arr[smallest].second) {
        smallest = right;
    }

    if (smallest != index) {
        std::swap(arr[index], arr[smallest]);
        heapifyDown(smallest);
    }
}
// size
int PriorityQueue::getSize() {
    return size;
}

int PriorityQueue::parent(int index) { return (index - 1) / 2; }
int PriorityQueue::leftChild(int index) { return 2 * index + 1; }
int PriorityQueue::rightChild(int index) { return 2 * index + 2; }