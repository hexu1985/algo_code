// range heap example
#include <iostream>     // std::cout
#include "heap.h"       // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap
#include <vector>       // std::vector

int main () {
  int myints[] = {10,20,30,5,15};
  std::vector<int> v(myints,myints+5);

  makeHeap (v, std::less<int>());
  std::cout << "initial max heap   : " << v.front() << '\n';

  popHeap (v, v.size(), std::less<int>()); v.pop_back();
  std::cout << "max heap after pop : " << v.front() << '\n';

  v.push_back(99); pushHeap (v, v.size(), std::less<int>());
  std::cout << "max heap after push: " << v.front() << '\n';

  sortHeap (v, std::less<int>());

  std::cout << "final sorted range :";
  for (unsigned i=0; i<v.size(); i++)
    std::cout << ' ' << v[i];

  std::cout << '\n';

  return 0;
}
