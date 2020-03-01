#include "polyLL.h"

int main(){
  /*
  PolyAsLL* poly1 = new PolyAsLL();
  std::cout<<"Poly1: ";
  poly1->writePoly();
  std::cout<<std::endl;*/
  PolyAsLL* poly2 = new PolyAsLL();
  std::cout<<"Poly2: ";
  poly2->writePoly();
  std::cout<<std::endl;
  //poly1->addPoly(poly2);
  poly2->squPoly();
}
