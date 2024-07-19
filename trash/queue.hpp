#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <string>
#include <stdexcept>


struct queueNode
{
  char key;
  float value;
  queueNode* next;
};

class PriorityQueue{
  public:
    PriorityQueue();
    ~PriorityQueue();
    void insert(char key, float value);
    void remove(char key);
    float search(char key);
  private:
    queueNode* head;
};

#endif // QUEUE_HPP