// is_heap example
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include "algorithm.h"  // is_heap_until, sort, reverse

int main () {
  std::vector<int> foo {9,8,2,3,6,4,5,1,7};

  auto last = is_heap_until (foo.begin(),foo.end());

  std::cout << "The " << (last-foo.begin()) << " first elements are a valid heap:";
  for (auto it=foo.begin(); it!=last; ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}

