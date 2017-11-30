// any_of example
#include <iostream>     // std::cout
#include <array>        // std::array
#include "algorithm.h"  // any_of

int main () {
  std::array<int,7> foo = {0,1,-1,3,-3,5,-5};

  if ( any_of(foo.begin(), foo.end(), [](int i){return i<0;}) )
    std::cout << "There are negative elements in the range.\n";

  return 0;
}
