#include <iostream>
#include <string>
#include "../include/hash.hpp"

using namespace std;

HashTable::HashTable(){
  for (int i = 0; i < TABLE_SIZE; i++){
    table[i] = NULL;
  }
}
HashTable::~HashTable(){
  for (int i= 0; i < TABLE_SIZE; i++){
    // deleta cada node na tabela
    HashNode* current = table[i];
    while (current!= nullptr){
      // itera em cada membro da lista encadeada relativo ao node específico
      // salva o endereço do próximo antes de apagar o anterior se não é impossivel acessar o próximo elemento da lista encadeada
      HashNode* preview = current;
      current = current->next;
      delete preview;
    }
  }
}
void HashTable::insert(char key, float value){
  HashNode* newNode = new HashNode;
  newNode->key = key;
  newNode->value = value;
  newNode->next = nullptr;

  int position = hashFunction(key);

  if( table[position] != nullptr ){
    HashNode* current = table[position];
    while (current->next != nullptr){
      HashNode* current = current->next;
    }
    current->next = newNode;
  }
  else{
    table[position] = newNode;
  }
}
void HashTable::remove(char key){
  int position = hashFunction(key);
  HashNode* current = table[position]; 

  if (current == nullptr){
    throw runtime_error("chave não encontrada");
  }

  if (current->key == key){
    table[position] = current->next;
    delete current;
  }
  
  while (current->next!= nullptr){
    HashNode* nextNodo = current->next;
    if(nextNodo->key == key){
      // sobreescreve o proximo do atual
      current->next = nextNodo->next;
      delete nextNodo;
      return;
    }
    // proximo
    current = current->next;
  }
  throw runtime_error("chave não encontrada");
}
float HashTable::search(char key){
  int position = hashFunction(key);
  HashNode* current = table[position];

  while (current != nullptr){
    if (current->key == key){
      return current->value;
    }
    current = current->next;
  }

  throw runtime_error("chave não encontrada");
}

int HashTable::hashFunction(char key){
  return static_cast<int>(key) % TABLE_SIZE;
};
