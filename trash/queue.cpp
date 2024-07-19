#include "../include/queue.hpp"

using namespace std;
PriorityQueue::PriorityQueue(){
  head = nullptr;
};

PriorityQueue::~PriorityQueue(){
  queueNode* current = head;
  while(current != nullptr){
    queueNode* next = current->next;
    delete current;
    current = next;
  }
};