#ifndef POLYASLL_H
#define POLYASLL_H

#include <iostream>
#include "LinkedList.h"

using namespace std;

class PolyAsLL{
 public:
  //member variables
  LinkedList* poly;

  //constructor
  PolyAsLL();

  //destructor
  ~PolyAsLL();

  //read polynomial
  void readPoly();

  //write polynomial
  void writePoly();

  //add polynomial
  void addPoly(PolyAsLL* secondPoly);

  //square polynomial
  void squPoly();
};

#endif
