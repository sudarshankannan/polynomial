#include "LinkedList.h"
#include <iostream>
using namespace std;

//Constructor
Node::Node(){}
Node::Node(int a, int b){
  this->data[0] = a;
  this->data[1] = b;
  this->next = NULL;
  this->prev = NULL;
}
Node::~Node(){
  this->next = NULL;
  this->prev = NULL;
}

LinkedList::LinkedList(){
  this->head = NULL;
  this->tail = NULL;
}
//add a node
void LinkedList::add(int a, int b){
  Node* nuNode = new Node(a, b);
  if(!head){
    this->head = nuNode;
    this->tail = nuNode;
    return;
  }
  else if(this->head==this->tail){
    this->head->next = nuNode;
    nuNode->prev = this->head;
    this->tail = nuNode;
  }
  else {
    this->tail->next = nuNode;
    nuNode->prev = this->tail;
    nuNode->next = NULL;
    this->tail = nuNode;
  }
}

void LinkedList::remove(Node* badNode){
  Node* temp;
  Node* p = this->head;
  while(p){
    if(badNode==this->head){
      this->head = p->next;
      delete p;
      this->head->prev = NULL;
    }
    if(badNode==this->tail){
      this->tail = p->prev;
      delete p;
      this->tail->next = NULL;
    }
    else{
      temp = p;
      p->next->prev = p->prev;
      p->prev->next = p->next;
      delete p;	
    }
    p = p->next;
  }
}
void LinkedList::printList(){
  Node* p = this->head;
  while(p!=NULL){
    std::cout<<p->data[0]<<"/"<<p->data[1]<<" ";
    p = p->next;
  }
  std::cout<<std::endl;
}
void LinkedList::sortList(){};
