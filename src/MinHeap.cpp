#include "../include/MinHeap.hpp"

// Constructor
MinHeap::MinHeap(int capacity) : capacity(capacity), size(0) {
    arr = new int[capacity];
}
// Destructor
MinHeap::~MinHeap() {
    delete[] arr;
}
// Insert
void MinHeap::insert(int data) {
    if (size == capacity) {
        cout << "Heap is full" << endl;
        return;
    }
    arr[size] = data;
    size++;
    heapifyUp(size - 1);
}
// Heapify Up
void MinHeap::heapifyUp(int index) {
    if (index == 0) return;
    int parent = (index - 1) / 2;
    if (arr[parent] > arr[index]) {
        swap(arr[parent], arr[index]);
        heapifyUp(parent);
    }
}
// Extract Min
int MinHeap::extractMin() {
    if (size == 0) {
        cout << "Heap is empty" << endl;
        return -1;
    }
    int min = arr[0];
    arr[0] = arr[size - 1];
    size--;
    heapifyDown(0);
    return min;
}
// Heapify Down
void MinHeap::heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int smallest = index;
    if (left < size && arr[left] < arr[smallest]) {
        smallest = left;
    }
    if (right < size && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if (smallest != index) {
        swap(arr[index], arr[smallest]);
        heapifyDown(smallest);
    }
}
// Print
void MinHeap::print() {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int MinHeap::getSize() {
    return size;
}
