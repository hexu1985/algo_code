// range heap example
#include <iostream>     // std::cout
#include <vector>       // std::vector
#include "algorithm.h"  // make_heap, pop_heap, push_heap, sort_heap

int main () {
  int myints[] = {10,20,30,5,15};
  std::vector<int> v(myints,myints+5);

  make_heap (v.begin(),v.end());
  std::cout << "initial max heap   : " << v.front() << '\n';

  pop_heap (v.begin(),v.end()); v.pop_back();
  std::cout << "max heap after pop : " << v.front() << '\n';

  v.push_back(99); push_heap (v.begin(),v.end());
  std::cout << "max heap after push: " << v.front() << '\n';

  sort_heap (v.begin(),v.end());

  std::cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++)
    std::cout << ' ' << v[i];

  std::cout << '\n';

  return 0;
}
