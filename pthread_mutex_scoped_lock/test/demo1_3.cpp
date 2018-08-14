// mutex example
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <pthread.h>      
#include "pthread_mutex_util.h"

pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;           // mutex for critical section

void print_block (int n, char c) {
  // critical section (exclusive access to std::cout signaled by locking mtx):
  pthread_mutex_scoped_lock guard(&mtx);
  for (int i=0; i<n; ++i) { std::cout << c; }
  std::cout << '\n';
}

int main ()
{
  std::thread th1 (print_block,50,'*');
  std::thread th2 (print_block,50,'$');

  th1.join();
  th2.join();

  return 0;
}

/*
Possible output (order of lines may vary, but characters are never mixed):

**************************************************
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/
