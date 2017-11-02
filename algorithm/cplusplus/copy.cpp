// copy algorithm example
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include "algorithm.h"  // copy

int main () {
  int myints[]={10,20,30,40,50,60,70};
  std::vector<int> myvector (7);

  copy ( myints, myints+7, myvector.begin() );

  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it = myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
