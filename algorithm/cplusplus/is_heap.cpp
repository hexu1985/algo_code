// is_heap example
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include "algorithm.h"  // is_heap, make_heap, pop_heap

int main () {
  std::vector<int> foo {9,5,2,6,4,1,3,8,7};

  if (!is_heap(foo.begin(),foo.end()))
    make_heap(foo.begin(),foo.end());

  std::cout << "Popping out elements:";
  while (!foo.empty()) {
    pop_heap(foo.begin(),foo.end());        // moves largest element to back
    std::cout << ' ' << foo.back();         // prints back
    foo.pop_back();                         // pops element out of container
  }
  std::cout << '\n';

  return 0;
}
