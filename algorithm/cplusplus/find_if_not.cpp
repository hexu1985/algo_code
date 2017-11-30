// find_if_not example
#include <iostream>     // std::cout
#include <array>        // std::array
#include "algorithm.h"  // find_if_not

int main () {
  std::array<int,5> foo = {1,2,3,4,5};

  std::array<int,5>::iterator it =
    find_if_not (foo.begin(), foo.end(), [](int i){return i%2;} );
  std::cout << "The first even value is " << *it << '\n';

  return 0;
}
