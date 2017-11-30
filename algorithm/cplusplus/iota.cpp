// iota example
#include <iostream>     // std::cout
#include "numeric.h"    // iota

int main () {
  int numbers[10];

  iota (numbers,numbers+10,100);

  std::cout << "numbers:";
  for (int& i:numbers) std::cout << ' ' << i;
  std::cout << '\n';

  return 0;
}
