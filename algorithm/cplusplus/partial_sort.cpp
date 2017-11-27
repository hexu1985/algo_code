// partial_sort example
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include "algorithm.h"  // partial_sort

bool myfunction (int i,int j) { return (i<j); }

int main () {
  int myints[] = {9,8,7,6,5,4,3,2,1};
  std::vector<int> myvector (myints, myints+9);

  // using default comparison (operator <):
  partial_sort (myvector.begin(), myvector.begin()+5, myvector.end());

  // using function as comp
  partial_sort (myvector.begin(), myvector.begin()+5, myvector.end(),myfunction);

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
