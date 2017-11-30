// includes algorithm example
#include <iostream>     // std::cout
#include "algorithm.h"  // includes, sort

bool myfunction (int i, int j) { return i<j; }

int main () {
  int container[] = {5,10,15,20,25,30,35,40,45,50};
  int continent[] = {40,30,20,10};

  sort (container,container+10);
  sort (continent,continent+4);

  // using default comparison:
  if ( includes(container,container+10,continent,continent+4) )
    std::cout << "container includes continent!\n";

  // using myfunction as comp:
  if ( includes(container,container+10,continent,continent+4, myfunction) )
    std::cout << "container includes continent!\n";

  return 0;
}


