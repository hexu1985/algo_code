// priority_queue::empty
#include <iostream>       // std::cout
#include "priority_queue.h"          // priority_queue

int main ()
{
  priority_queue<int> mypq;
  int sum (0);

  for (int i=1;i<=10;i++) mypq.push(i);

  while (!mypq.empty())
  {
     sum += mypq.top();
     mypq.pop();
  }

  std::cout << "total: " << sum << '\n';

  return 0;
}
