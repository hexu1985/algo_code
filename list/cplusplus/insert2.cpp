// inserting into a list
#include <iostream>
#include "list.h"
#include <vector>

int main ()
{
  list<int> mylist;
  list<int>::iterator it;
  list<int>::iterator ret;

  // set some initial values:
  for (int i=1; i<=5; ++i) mylist.push_back(i); // 1 2 3 4 5

  it = mylist.begin();
  ++it;       // it points now to number 2           ^

  ret = mylist.insert (it,10);                  // 1 10 2 3 4 5
  std::cout << "ret: " << *ret << ", " 
      << "--ret: " << *--ret << std::endl;

  // "it" still points to number 2                      ^
  ret = mylist.insert (it,2,20);                // 1 10 20 20 2 3 4 5
  std::cout << "ret: " << *ret << ", " 
      << "--ret: " << *--ret << std::endl;

  --it;       // it points now to the second 20            ^

  std::vector<int> myvector (2,30);
  ret = mylist.insert (it,myvector.begin(),myvector.end());
  std::cout << "ret: " << *ret << ", " 
      << "--ret: " << *--ret << std::endl;
                                                // 1 10 20 30 30 20 2 3 4 5
                                                //               ^
  std::cout << "mylist contains:";
  for (it=mylist.begin(); it!=mylist.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
