// erasing from list
#include <iostream>
#include <iterator>
#include "dclist.h"
#include "dclist_iterator.h"
#include "dclist_util.h"

int main ()
{
  DCList<int> mylist;
  list_init(&mylist);
  DCList_iterator<int> it1,it2;

  // set some values:
  for (int i=1; i<10; ++i) list_insert_tail(&mylist, new DCList_node<int>(i*10));

                                   // 10 20 30 40 50 60 70 80 90
  it1 = it2 = list_begin(&mylist); // ^^
  std::advance (it2,6);            // ^                 ^
  ++it1;                           //    ^              ^

  auto node = it1.get_node();      // 10 30 40 50 60 70 80 90
  it1++;
  list_delete(node);               //    ^           ^
  delete node;

  node = it2.get_node();           // 10 30 40 50 60 80 90
  it2++;
  list_delete(node);               //    ^           ^
  delete node;

  ++it1;                           //       ^        ^
  --it2;                           //       ^     ^

  auto node1 = it1.get_node();
  auto node2 = it2.get_node();     // 10 30 60 80 90
  if (node1 != node2) {            //        ^
      list_delete(node1, list_prev(node2));
  }
  while (node1 != node2) {
      node = list_next(node1);
      delete node1;
      node1 = node;
  }

  std::cout << "mylist contains:";
  for (auto it=list_begin(&mylist); it != list_end(&mylist); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
