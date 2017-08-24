// array::max_size
#include <iostream>
#include "array.h"

int main ()
{
  array<int,10> myints;
  std::cout << "size of myints: " << myints.size() << '\n';
  std::cout << "max_size of myints: " << myints.max_size() << '\n';

  return 0;
}
