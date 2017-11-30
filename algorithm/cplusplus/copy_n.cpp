// copy_n algorithm example
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include "algorithm.h"  // copy_n

int main () {
  int myints[]={10,20,30,40,50,60,70};
  std::vector<int> myvector;

  myvector.resize(7);   // allocate space for 7 elements

  copy_n ( myints, 7, myvector.begin() );

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
