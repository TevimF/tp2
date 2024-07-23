#include "../include/main.hpp"
#include "../include/graph_lista.hpp"
#include "graph_matriz.cpp"

#define MAX_SIZE 100
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
   int element[MAX_SIZE];
  for (int i = 0; i < a; i++){
    cin >> element[i];
  }

  cout << "Hello, World!" << endl;
  cout << "a: " << a << endl;
  cout << "b: " << b << endl;
  cout << "c: " << c << endl;
  cout << "element: " << endl;
  for (int i = 0; i < a; i++){
    cout << element[i] << " ";
  }
}
