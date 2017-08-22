// swap lists
#include <iostream>
#include "dclist.h"
#include "dclist_iterator.h"
#include "dclist_util.h"

int main ()
{
  DCList<int> first; list_init(&first, 3,100);   // three ints with a value of 100
  DCList<int> second; list_init(&second, 5,200);  // five ints with a value of 200

  list_swap(&first, &second);

  std::cout << "first contains:";
  std::cout << "mylist contains:";
  for (auto it=list_begin(&first); it != list_end(&first); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "second contains:";
  for (auto it=list_begin(&second); it != list_end(&second); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
