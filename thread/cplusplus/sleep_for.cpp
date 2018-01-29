// this_thread::sleep_for example
#include <iostream>       // std::cout, std::endl
#include "thread.h"       // this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
 
int main() 
{
  std::cout << "countdown:\n";
  for (int i=10; i>0; --i) {
    std::cout << i << std::endl;
    this_thread::sleep_for (std::chrono::seconds(1));
  }
  std::cout << "Lift off!\n";

  return 0;
}
