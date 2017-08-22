// list::remove_if
#include <iostream>
#include "dclist.h"
#include "dclist_iterator.h"
#include "dclist_util.h"

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
  bool operator() (const int& value) { return (value%2)==1; }
};

int main ()
{
  int myints[]= {15,36,7,17,20,39,4,1};
  DCList<int> mylist;
  list_init(&mylist,myints,myints+8);   // 15 36 7 17 20 39 4 1

  list_remove_if (&mylist, single_digit);           // 15 36 17 20 39

  list_remove_if (&mylist, is_odd());               // 36 20

  std::cout << "mylist contains:";
  for (auto it=list_begin(&mylist); it != list_end(&mylist); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
