#include <assert.h>
#include <iostream>

#include "thread.h"

Thread::Thread(const std::string &name): name_(name) {
}

Thread::~Thread() {
    if (is_run()) {
        stop();
    }
}

void Thread::start() {
    assert(!thread_ && !task_queue_);
    task_queue_ = boost::shared_ptr<Task_queue>(new Task_queue);
    thread_ = boost::shared_ptr<boost::thread>(new boost::thread(&Thread::task_process, this));
}

void Thread::stop() {
    thread_->interrupt();
    thread_->join();
    thread_.reset();
    task_queue_.reset();
}

void Thread::task_process()
{
    Task_queue &incoming_queue = *task_queue_;
	while (true) {
        std::deque<boost::shared_ptr<Task_base> > working_queue;
		incoming_queue.swap_task_queue(working_queue);
		while (!working_queue.empty()) {
			boost::shared_ptr<Task_base> task = working_queue.front();
			working_queue.pop_front();
			task->run();
		}
	}
}
