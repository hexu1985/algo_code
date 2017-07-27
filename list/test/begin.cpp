// list::begin
#include <iostream>
#include "dclist.h"
#include "dclist_iterator.h"
#include "dclist_util.h"

int main ()
{
  DCList<int> mylist;
  int myints[] = {75,23,65,42,13};
  list_init(&mylist,myints,myints+5);

  std::cout << "mylist contains:";
  for (auto it=list_begin(&mylist); it != list_end(&mylist); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  list_destroy(&mylist);
  return 0;
}
