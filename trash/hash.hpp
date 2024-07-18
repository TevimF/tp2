#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
const int TABLE_SIZE = 128;

struct HashNode {
  // chave
  char key;
  // valor armazenado
  float value;
  // próximo item
  HashNode* next;
};

class HashTable {
  public:
    HashTable();
    ~HashTable();
    void insert(char key, float value);
    void remove(char key);
    float search(char key);
  private:
    // cria um array de ponteiros para HashNode
    HashNode* table[TABLE_SIZE];
    // função de hash que retorna o lugar a ser alocada a chave
    int hashFunction(char key);
};

#endif // QUEUE_HPP