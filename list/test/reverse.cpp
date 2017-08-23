// reversing list
#include <iostream>
#include "dclist.h"
#include "dclist_iterator.h"
#include "dclist_util.h"

int main ()
{
  DCList<int> mylist;
  list_init(&mylist);

  for (int i=1; i<10; ++i) list_insert_tail(&mylist, new DCList_node<int>(i));

  list_reverse(&mylist);

  std::cout << "mylist contains:";
  for (auto it=list_begin(&mylist); it != list_end(&mylist); ++it)
    std::cout << ' ' << *it;

  std::cout << '\n';

  return 0;
}
