// lower_bound/upper_bound example
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include "algorithm.h"  // lower_bound, upper_bound, sort

int main () {
  int myints[] = {10,20,30,30,20,10,10,20};
  std::vector<int> v(myints,myints+8);           // 10 20 30 30 20 10 10 20

  sort (v.begin(), v.end());                	 // 10 10 10 20 20 20 30 30

  std::vector<int>::iterator low,up;
  low=lower_bound (v.begin(), v.end(), 20); 	 //          ^
  up= upper_bound (v.begin(), v.end(), 20); 	 //                   ^

  std::cout << "lower_bound at position " << (low- v.begin()) << '\n';
  std::cout << "upper_bound at position " << (up - v.begin()) << '\n';

  return 0;
}
