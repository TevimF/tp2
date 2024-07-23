#ifndef MIN_HEAP_HPP
#define MIN_HEAP_HPP

#include <stdexcept>

class MinHeap {
public:
    MinHeap(size_t capacity);
    ~MinHeap();

    void insert(int value);
    int extractMin();
    int getMin() const;
    bool isEmpty() const;
    size_t size() const;

private:
    int* heap;
    size_t heapSize;
    size_t capacity;

    void heapifyUp(size_t index);
    void heapifyDown(size_t index);
    size_t parent(size_t index) const;
    size_t leftChild(size_t index) const;
    size_t rightChild(size_t index) const;

    void resize();
};

#endif // MIN_HEAP_HPP
