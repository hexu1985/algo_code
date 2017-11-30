// clearing lists
#include <iostream>
#include "dclist.h"
#include "dclist_iterator.h"
#include "dclist_util.h"

int main ()
{
  DCList<int> mylist;
  DCList_iterator<int> it;
  list_init(&mylist);

  list_insert_tail(&mylist, new DCList_node<int>(100));
  list_insert_tail(&mylist, new DCList_node<int>(200));
  list_insert_tail(&mylist, new DCList_node<int>(300));

  std::cout << "mylist contains:";
  for (it=list_begin(&mylist); it != list_end(&mylist); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  list_clear(&mylist);
  list_insert_tail(&mylist, new DCList_node<int>(1101));
  list_insert_tail(&mylist, new DCList_node<int>(2202));

  std::cout << "mylist contains:";
  for (it=list_begin(&mylist); it != list_end(&mylist); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
