#include "../include/min_heap.hpp"
#include <stdexcept>

MinHeap::MinHeap(size_t initialCapacity)
  : heapSize(0), capacity(initialCapacity) {
  heap = new int[capacity];
}

MinHeap::~MinHeap() {
  delete[] heap;
}

void MinHeap::insert(int value) {
  if (heapSize == capacity) {
      resize();
  }
  heap[heapSize] = value;
  heapifyUp(heapSize);
  heapSize++;
}

int MinHeap::extractMin() {
  if (heapSize == 0) {
    throw std::runtime_error("Heap vazio");
  }

  int min = heap[0];
  heapSize--;
  heap[0] = heap[heapSize];
  heapifyDown(0);

  return min;
}

int MinHeap::getMin() const {
  if (heapSize == 0) {
    throw std::runtime_error("Heap vazio");
  }
  return heap[0];
}

bool MinHeap::isEmpty() const {
  return heapSize == 0;
}

size_t MinHeap::size() const {
  return heapSize;
}

void MinHeap::heapifyUp(size_t index) {
  while (index > 0 && heap[index] < heap[parent(index)]) {
    std::swap(heap[index], heap[parent(index)]);
    index = parent(index);
  }
}

void MinHeap::heapifyDown(size_t index) {
  size_t smallest = index;
  size_t left = leftChild(index);
  size_t right = rightChild(index);

  if (left < heapSize && heap[left] < heap[smallest]) {
    smallest = left;
  }

  if (right < heapSize && heap[right] < heap[smallest]) {
    smallest = right;
  }

  if (smallest != index) {
    std::swap(heap[index], heap[smallest]);
    heapifyDown(smallest);
  }
}

size_t MinHeap::parent(size_t index) const {
  return (index - 1) / 2;
}

size_t MinHeap::leftChild(size_t index) const {
  return 2 * index + 1;
}

size_t MinHeap::rightChild(size_t index) const {
  return 2 * index + 2;
}

void MinHeap::resize() {
  size_t newCapacity = capacity * 2;
  int* newHeap = new int[newCapacity];

  for (size_t i = 0; i < heapSize; ++i) {
    newHeap[i] = heap[i];
  }

  delete[] heap;
  heap = newHeap;
  capacity = newCapacity;
}


