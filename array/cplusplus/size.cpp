// array::size
#include <iostream>
#include "array.h"

int main ()
{
  array<int,5> myints;
  std::cout << "size of myints: " << myints.size() << std::endl;
  std::cout << "sizeof(myints): " << sizeof(myints) << std::endl;

  return 0;
}
