// list::unique
#include <iostream>
#include <cmath>
#include "dclist.h"
#include "dclist_iterator.h"
#include "dclist_util.h"

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
  bool operator() (double first, double second)
  { return (fabs(first-second)<5.0); }
};

int main ()
{
  double mydoubles[]={ 12.15,  2.72, 73.0,  12.77,  3.14,
                       12.77, 73.35, 72.25, 15.3,  72.25 };
  DCList<double> mylist;
  list_init(&mylist, mydoubles,mydoubles+10);
  
  list_sort(&mylist);             //  2.72,  3.14, 12.15, 12.77, 12.77,
                                  // 15.3,  72.25, 72.25, 73.0,  73.35

  list_unique(&mylist);           //  2.72,  3.14, 12.15, 12.77
                                  // 15.3,  72.25, 73.0,  73.35

  list_unique (&mylist, same_integral_part);  //  2.72,  3.14, 12.15
                                              // 15.3,  72.25, 73.0

  list_unique (&mylist, is_near());           //  2.72, 12.15, 72.25

  std::cout << "mylist contains:";
  for (auto it=list_begin(&mylist); it != list_end(&mylist); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
