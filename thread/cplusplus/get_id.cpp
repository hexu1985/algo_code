// thread::get_id / this_thread::get_id
#include <iostream>       // std::cout
#include "thread.h"       // thread, thread::id, this_thread::get_id
#include <chrono>         // std::chrono::seconds
 
thread::id main_thread_id = this_thread::get_id();

void is_main_thread() {
  if ( main_thread_id == this_thread::get_id() )
    std::cout << "This is the main thread.\n";
  else
    std::cout << "This is not the main thread.\n";
}

int main() 
{
  is_main_thread();
  thread th (is_main_thread);
  th.join();
}
