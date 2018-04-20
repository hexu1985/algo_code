// is_heap example
#include <iostream>     // std::cout
#include <algorithm>    // std::is_heap_until, std::sort, std::reverse
#include <vector>       // std::vector
#include "heap.h"

int main () {
  std::vector<int> foo {9,8,2,3,6,4,5,1,7};

  auto last = isHeapUntil (foo,std::less<int>());

  std::cout << "The " << last+1 << " first elements are a valid heap:";
  for (auto it=foo.begin(); it!=foo.begin()+last; ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
