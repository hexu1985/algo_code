// remove from list
#include <iostream>
#include "dclist.h"
#include "dclist_iterator.h"
#include "dclist_util.h"

int main ()
{
  int myints[]= {17,89,7,14};
  DCList<int> mylist;
  list_init(&mylist,myints,myints+4);

  list_remove(&mylist, 89);

  std::cout << "mylist contains:";
  for (auto it=list_begin(&mylist); it != list_end(&mylist); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
