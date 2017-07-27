// constructing lists
#include <iostream>
#include "dclist.h"
#include "dclist_iterator.h"
#include "dclist_util.h"

int main ()
{
  // constructors used in the same order as described above:
  DCList<int> first;                        // empty DCList of ints
  list_init(&first);

  DCList<int> second;                       // four ints with value 100
  list_init(&second, 4, 100);

  DCList<int> third;                        // iterating through second
  list_init(&third, list_begin(&second), list_end(&second));

  DCList<int> fourth;                       // a copy of third
  list_init(&fourth, list_begin(&third), list_end(&third));

  // the iterator constructor can also be used to construct from arrays:
  int myints[] = {16,2,77,29};
  DCList<int> fifth;
  list_init(&fifth, myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are: ";
  for (auto it = list_begin(&fifth); it != list_end(&fifth); it++)
    std::cout << *it << ' ';

  std::cout << '\n';

  return 0;
}
