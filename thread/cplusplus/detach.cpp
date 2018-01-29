#include <iostream>       // std::cout
#include "thread.h"       // thread, this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
 
void pause_thread(int n) 
{
  this_thread::sleep_for (std::chrono::seconds(n));
  std::cout << "pause of " << n << " seconds ended\n";
}
 
int main() 
{
  std::cout << "Spawning and detaching 3 threads...\n";
  thread (pause_thread,1).detach();
  thread (pause_thread,2).detach();
  thread (pause_thread,3).detach();
  std::cout << "Done spawning threads.\n";

  std::cout << "(the main thread will now pause for 5 seconds)\n";
  // give the detached threads time to finish (but not guaranteed!):
  pause_thread(5);
  return 0;
}
