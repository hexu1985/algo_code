// nth_element example
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include "algorithm.h"  // nth_element, random_shuffle

bool myfunction (int i,int j) { return (i<j); }

int main () {
  std::vector<int> myvector;

  // set some values:
  for (int i=1; i<10; i++) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9

  random_shuffle (myvector.begin(), myvector.end());

  // using default comparison (operator <):
  nth_element (myvector.begin(), myvector.begin()+5, myvector.end());

  // using function as comp
  nth_element (myvector.begin(), myvector.begin()+5, myvector.end(),myfunction);

  // print out content:
  std::cout << "myvector contains:";
  for (std::vector<int>::iterator it=myvector.begin(); it!=myvector.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
