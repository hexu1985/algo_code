// mutex::lock/unlock
#include <iostream>       // std::cout
#include <thread>         // std::thread
#include <pthread.h>      

pthread_mutex_t mtx;           // mutex for critical section

void print_thread_id (int id) {
  // critical section (exclusive access to std::cout signaled by locking mtx):
  pthread_mutex_lock(&mtx);
  std::cout << "thread #" << id << '\n';
  pthread_mutex_unlock(&mtx);
}

int main ()
{
  pthread_mutex_init(&mtx, NULL);
  std::thread threads[10];
  // spawn 10 threads:
  for (int i=0; i<10; ++i)
    threads[i] = std::thread(print_thread_id,i+1);

  for (auto& th : threads) th.join();
  pthread_mutex_destroy(&mtx);

  return 0;
}

/*
Possible output (order of lines may vary, but they are never intermingled):
thread #1
thread #2
thread #3
thread #4
thread #5
thread #6
thread #7
thread #8
thread #9
thread #10
*/
