#include "../include/PriorityQueue.hpp"

// Constructor
PriorityQueue::PriorityQueue(int capacidade) : capacity(capacidade), size(0) {
    arr = new int[capacidade];
}
// Destructor
PriorityQueue::~PriorityQueue() {
    delete[] arr;
}
// Insert
void PriorityQueue::insert(int data) {
    if (size == capacity) {
        cout << "Heap is full" << endl;
        return;
    }
    arr[size] = data;
    size++;
    heapifyUp(size - 1);
}
// Heapify Up
void PriorityQueue::heapifyUp(int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (arr[parent] < arr[index]) {
        swap(arr[parent], arr[index]);
        heapifyUp(parent);
    }
}
// Extract Max
int PriorityQueue::extractMax() {
    if (size == 0) {
        cout << "Heap is empty" << endl;
        return -1;
    }
    int max = arr[0];
    arr[0] = arr[size - 1];
    size--;
    heapifyDown(0);
    return max;
}
// Heapify Down
void PriorityQueue::heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;
    if (left < size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(arr[index], arr[largest]);
        heapifyDown(largest);
    }
}
