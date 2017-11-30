// minmax_element
#include <iostream>     // std::cout
#include <array>        // std::array
#include "algorithm.h"  // minmax_element

int main () {
  std::array<int,7> foo {3,7,2,9,5,8,6};

  auto result = minmax_element (foo.begin(),foo.end());

  // print result:
  std::cout << "min is " << *result.first;
  std::cout << ", at position " << (result.first-foo.begin()) << '\n';
  std::cout << "max is " << *result.second;
  std::cout << ", at position " << (result.second-foo.begin()) << '\n';

  return 0;
}
