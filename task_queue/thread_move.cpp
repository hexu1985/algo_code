#include <sstream>
#include <iostream>
#include <vector>
#include "thread.h"

void print_string(std::string str)
{
	std::cout << __func__ << "(" << str << ")" << std::endl;
}

int main()
{
    std::vector<Thread> mythreads;
    mythreads.push_back(Thread("thread-1"));
    mythreads.push_back(Thread("thread-2"));

    for (auto &thr: mythreads) {
        thr.start();
    }

	for (int i = 0; i < 10; i++) {
        auto &thr = mythreads[i%2];
        auto task_queue = thr.get_task_queue();
		task_queue->push_task(make_task(print_string, std::string(thr.name())));
	}

    char c;
    std::cin >> c;

    for (auto &thr: mythreads) {
        thr.stop();
    }

	return 0;
}

