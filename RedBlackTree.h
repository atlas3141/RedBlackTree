//Josh Howel Red Black Tree
//A self sorting and balancing tree thing 

#include <iostream>
#include "Node.h"

using namespace std;

class RedBlackTree{
 private:
  Node* head;

 public:
  RedBlackTree();
  void add(Node* current, int number);  
  void print(Node* current, int indent = 0);
  Node* getHead();

};
