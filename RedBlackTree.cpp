#include "RedBlackTree.h"

using namespace std;

RedBlackTree::RedBlackTree(){
  head = NULL;
}

void RedBlackTree::rotateLeft(Node* current){
  Node* newHead = current->getRight();
  if (current == head){
    head = newHead;
      }
  else if (current->isRight()){
    current->getParent()->setRight(newHead);
  }
  else{
    current->getParent()->setLeft(newHead);
  }
  current->setRight(newHead->getLeft());
  newHead->setLeft(current);
  
  
}
void RedBlackTree::rotateRight(Node* current){
  Node* newHead = current->getLeft();
  if (current == head){
    head = newHead;
      }
  else if (current->isRight()){
    current->getParent()->setRight(newHead);
  }
  else{
    current->getParent()->setLeft(newHead);
  }
  current->setLeft(newHead->getRight());
  newHead->setRight(current);

}
void RedBlackTree::fix(Node* current){
  if (current->isRed() && current->getParent()->isRed()){
    if(current->isRight()  && !current->getParent()->isRight()){
      rotateLeft(current->getParent());
      current = current->getLeft();
    }
    else if(!current->isRight() && current->getParent()->isRight()){
      rotateRight(current->getParent());
      current = current->getRight();
    }
    if (!current->getUncle()->isRed()){
      if(current->isRight()){
	current->getParent()->getParent()->setRed(true);
	current->getParent()->setRed(false);
	rotateLeft(current->getParent()->getParent());
      }
      else{
	current->getParent()->getParent()->setRed(true);
	current->getParent()->setRed(false);
	rotateRight(current->getParent()->getParent());
      }
    }
    else if (current->getUncle()->isRed()){
      current->getUncle()->setRed(false);
      current->getParent()->setRed(false);
      current->getParent()->getParent()->setRed(true);
      fix(current->getParent()->getParent());
    }
  }
  head->setRed(false);
}
void RedBlackTree::add(Node* current, int number){
  if (head == NULL){
   
    head = new Node(number);
    head->setRed(false);
  }
  else{
 
    if (number < current->getData()){
      if (current->getLeft()){
	add(current->getLeft(),number);
      }
      else{
	Node* newNode = new Node(number);
	current->setLeft(newNode);
	fix(newNode);
      }
    }
    if (number > current->getData()){
      if (current->getRight()){
	add(current->getRight(),number);
      }
      else{
	Node* newNode = new Node(number);
	current->setRight(newNode);
	fix(newNode);
      }
    }
  }
}
void RedBlackTree::print(Node* current, int indent){
  if(current->getRight()){
    print(current->getRight(), indent+1);
  }
  for (int i = 0; i < indent; i++){
    cout << "  ";
  }
  cout << current->getData() << " "; 
  current->isRed() ? cout << "R" << endl : cout << "B" << endl;
  if(current->getLeft()){
    print(current->getLeft(), indent+1);
  }
}
Node* RedBlackTree::getHead(){
  return head;
}
