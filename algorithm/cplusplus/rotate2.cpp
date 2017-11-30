// rotate algorithm example
#include <iostream>     // std::cout
#include <forward_list>       // std::forward_list
#include "algorithm.h"  // rotate

int main () {
  std::forward_list<int> mylst = {1, 2, 3, 4, 5, 6, 7, 8, 9};   // 1 2 3 4 5 6 7 8 9

  auto middle = mylst.begin();
  std::advance(middle,3);
  rotate(mylst.begin(),middle,mylst.end());
                                                  // 4 5 6 7 8 9 1 2 3
  // print out content:
  std::cout << "mylst contains:";
  for (std::forward_list<int>::iterator it=mylst.begin(); it!=mylst.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
