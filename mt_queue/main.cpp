#include <iostream>
#include <cstdio>
#include <thread>

#include "mt_queue.hpp"

void push(queue<int>* q)
{
    for (int i = 0; i < 10; ++i) {
        //std::cout << "pushing " << i << std::endl;
        printf("pushing %d\n", i);
        q->push(i);
    }
}

void pop(queue<int>* q)
{
    for (int i = 0; i < 10; ++i) {
        printf("poping %d\n", *q->wait_and_pop());
    }
}
    
int main()
{
    queue<int> q;
    std::thread t1(push,&q);
    std::thread t2(pop,&q);
    t1.join();
    t2.join();
    return 0;
}

