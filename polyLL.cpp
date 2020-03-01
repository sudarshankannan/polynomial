#include "LinkedList.h"
#include "polyLL.h"
#include <vector>
#include <map>
#include <iterator>

//constructor
PolyAsLL::PolyAsLL(){
  this->poly = new LinkedList();
  this->readPoly();
  //this->poly->sortList();
}
//destructor
PolyAsLL::~PolyAsLL(){
  delete this->poly;
}

//read input for polynomial
void PolyAsLL::readPoly(){
  std::vector<int>* input = new vector<int>();
  bool keepGoing = true;
  int i;
  while(keepGoing){
    //get coefficient
    std::cout<<"Enter polynomial coefficient: ";
    std::cin>>i;
    std::cout<< std::endl;
    input->push_back(i);
    //get power
    std::cout<<"Enter polynomial power: ";
    std::cin>>i;
    std::cout<<std::endl;
    input->push_back(i);
    //see if user wants to add more
    std::cout<<"Press 1 to continue, 0 to end: ";
    std::cin>>i;
    std::cout<<std::endl;
    if(i ==0)
      keepGoing = false;
  }
  for(int i=0; i<input->size(); i++){
    std::cout<<input->at(i)<<std::endl;
  }
  if(input->size() % 2 !=0){
    std::cout<<"You are missing a power input. Cannot use this polynomial"<<std::endl;
    return;
  }
  else{
    std::cout<<"enter"<<std::endl;
    int tempArray[2];
    for(int i=0; i<input->size(); i+=2){
      if(i>=input->size())
	break;
      std::cout<<"i: "<<i<<std::endl;
      //tempArray[i] = input->at(i);
      //tempArray[i+1] = input->at(i+1);
      if(input->at(i) != 0)
	this->poly->add(input->at(i),input->at(i+1));
    }
    return;
  }
}

//write polynomial
void PolyAsLL::writePoly(){
  Node* p = this->poly->head;
  while(p){
    std::cout<<p->data[0]<<"/"<<p->data[1]<<" ";
    p = p->next;
  }
  std::cout<<std::endl;
  return;
}

//add polynomials
void PolyAsLL::addPoly(PolyAsLL* secondPoly){
  Node* poly1Term = this->poly->head;
  Node* poly2Term = secondPoly->poly->head;
  //0-coeff, 1-powers
  int arr[2];
  LinkedList* sum = new LinkedList();
  bool term1Added = false;
  bool term2Added = false;
  while(poly1Term && poly2Term){
    std::cout<<"begin"<<std::endl;
    //current terms are of the same power
    if(poly1Term->data[1] == poly2Term->data[1]){
      arr[0] = poly1Term->data[0] + poly2Term->data[0];
      arr[1] = poly1Term->data[1];
      sum->add(arr[0],arr[1]);
      term1Added = true;
      term2Added = true;
      std::cout<<"terms summed: "<<arr[0]<<"/"<<arr[1]<<std::endl;
    }
    //term 1 less than term 2
    else if(poly1Term->data[1] < poly2Term->data[1]){
      //add term 2 to sum
      arr[0] = poly2Term->data[0];
      arr[1] = poly2Term->data[1];
      sum->add(arr[0],arr[1]);
      term2Added = true;
      std::cout<<arr[0]<<"/"<<arr[1]<<std::endl;
      //in this case term 1 should go right after term 2
      if(poly2Term->next && poly1Term->data[1] > poly2Term->next->data[1]){;
	arr[0] = poly1Term->data[0];
	arr[1] = poly1Term->data[1];
	sum->add(arr[0],arr[1]);
	term1Added = true;
	std::cout<<arr[0]<<"/"<<arr[1]<<"added"<<std::endl;
      }
    }
    //term 1 greater than term 2, goes right in front of term 2
    else if(poly1Term->data[1] > poly2Term->data[1]){
      arr[0] = poly1Term->data[0];
      arr[1] = poly1Term->data[1];
      sum->add(arr[0],arr[1]);
      term1Added = true;
      std::cout<<arr[0]<<"/"<<arr[1]<<" added"<<std::endl;
    }
    if(term1Added){
      term1Added = false;
      poly1Term = poly1Term->next;
    }
    if(term2Added){
      term2Added = false;
      poly2Term = poly2Term->next;
    }
    if(poly1Term)
      std::cout<<"PolyTerm1 at End: "<<poly1Term->data[0]<<"/"<<poly1Term->data[1]<<std::endl;
    if(poly2Term)
      std::cout<<"PolyTerm2 at End: "<<poly2Term->data[0]<<"/"<<poly2Term->data[1]<<std::endl;
    std::cout<<"end of loop iteration"<<std::endl;
  }
  std::cout<<"loop full exit"<<std::endl;
    
  //add any remaining terms to sum polynomial
  if(poly2Term){
    std::cout<<"adding remaining poly2Terms"<<std::endl;
    while(poly2Term){
      arr[0] = poly2Term->data[0];
      arr[1] = poly2Term->data[1];
      sum->add(arr[0],arr[1]);
      poly2Term = poly2Term->next;
    }
  }
  if(poly1Term){
    std::cout<<"adding remaining poly1Terms"<<std::endl;
    while(poly1Term){
      arr[0] = poly1Term->data[0];
      arr[1] = poly1Term->data[1];
      sum->add(arr[0],arr[1]);
      poly1Term = poly1Term->next;
    }
  }
  //print sum
  sum->printList();
}

//square polynomial
void PolyAsLL::squPoly(){
  Node* a = this->poly->head;
  Node* b = this->poly->head;
  std::map<int,int> terms;
  int coeff;
  int power;
  while(a){
    Node* currMult = b;
    while(currMult){
      coeff = a->data[0] * currMult->data[0];
      power = a->data[1] + currMult->data[1];
      if(terms.find(power) == terms.end())
	terms.insert(std::pair<int, int>(power, coeff));
      else
	terms.find(power)->second += coeff;
      currMult = currMult->next;
    }
    a = a->next;
  }
  //create ll and print out square
  map<int, int>::iterator itr;
  std::cout<<"Number of terms: "<<terms.size()<<std::endl;
  LinkedList l;
  for (itr = terms.end(); itr != terms.begin(); --itr) { 
    l.add(itr->second, itr->first);
  }
  l.printList();
}
