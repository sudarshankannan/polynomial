#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
using namespace std;

class Node{
 public:
  //Member variables
  int data[2];
  Node* next;
  Node* prev;
  //Constructor
  Node();
  Node(int a, int b);
  ~Node();
};

class LinkedList{
 public:
  //Member Variables
  Node* head;
  Node* tail;
  //Constructors
  LinkedList();
  //add a node
  void add(int a, int b);
  void remove(Node* badNode);
  void printList();
  void sortList();
};

#endif
