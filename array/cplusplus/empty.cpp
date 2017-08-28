// array::empty
#include <iostream>
#include "array.h"

int main ()
{
  array<int,0> first;
  array<int,5> second;
  std::cout << "first " << (first.empty() ? "is empty" : "is not empty") << '\n';
  std::cout << "second " << (second.empty() ? "is empty" : "is not empty") << '\n';
  return 0;
}
