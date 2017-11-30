// is_sorted example
#include <iostream>     // std::cout
#include <array>        // std::array
#include "algorithm.h"  // is_sorted, prev_permutation

int main () {
  std::array<int,4> foo {2,4,1,3};

  do {
    // try a new permutation:
    prev_permutation(foo.begin(),foo.end());

    // print range:
    std::cout << "foo:";
    for (int& x:foo) std::cout << ' ' << x;
    std::cout << '\n';

  } while (!is_sorted(foo.begin(),foo.end()));

  std::cout << "the range is sorted!\n";

  return 0;
}
