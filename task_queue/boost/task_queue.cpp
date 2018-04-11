#include <utility>
#include <functional>
#include <deque>
#include <boost/thread/mutex.hpp>
#include <boost/thread/thread.hpp>
#include <memory>
#include <iostream>
#include <string>

struct Task_base {
	virtual ~Task_base() {}
	virtual void run() = 0;
};

template <typename Fn>
struct Task: public Task_base {
	Task(const Fn &fn): f_(fn) {}

	virtual void run() { f_(); }

	Fn f_;
};

template <typename Fn>
Task<Fn> *make_task(const Fn &fn)
{
	return new Task<Fn>(fn);
}

class Task_queue: public std::deque<Task_base *> {
	boost::mutex queue_mtx_;

public:
	void post_task(Task_base *task) {
		boost::lock_guard<boost::mutex> lck(queue_mtx_);
		this->push_back(task);
	}	

	void swap_task(std::deque<Task_base *> &task_queue) {
		boost::lock_guard<boost::mutex> lck(queue_mtx_);
		if (!this->empty()) {
			this->swap(task_queue);
		}
	}
};

void processor(Task_queue &incoming_queue)
{
	while (true) {
        std::deque<Task_base *> work_queue;
		incoming_queue.swap_task(work_queue);
		while (!work_queue.empty()) {
			Task_base *task = work_queue.front();
			work_queue.pop_front();
			task->run();
			delete task;
		} 
        boost::this_thread::interruption_point();
	}
}

void print_int(int i)
{
	std::cout << __func__ << "(" << i << ")" << std::endl;
}

void print_string(std::string str)
{
	std::cout << __func__ << "(" << str << ")" << std::endl;
}

void print_string_ref(std::string &str)
{
    std::cout << __func__ << "(" << str << ")" << std::endl;
    str += ".";
}

class Foo {
	int n_;
public:
	Foo(int n): n_(n) {}

	void print()
	{
		std::cout << "Foo::" << __func__ << "(" << n_++ << ")" << std::endl;
	}
};

void process_exit()
{
	std::cout << "task to stop process thread" << std::endl;
	pthread_exit(NULL);
}

int main()
{
	Foo foo(1);

	Task_queue task_queue;
	boost::thread proc_thread(processor, boost::ref(task_queue));
    std::string str = "hello";
	for (int i = 0; i < 10; i++) {
		task_queue.post_task(make_task(boost::bind(print_int, i)));
		task_queue.post_task(make_task(boost::bind(print_string, std::string("hello"))));
		task_queue.post_task(make_task(boost::bind(print_string_ref, boost::ref(str))));
		task_queue.post_task(make_task(boost::bind(&Foo::print, &foo)));
	}
//	task_queue.post_task(make_task(boost::bind(process_exit)));
    proc_thread.interrupt();
	proc_thread.join();
	return 0;
}

