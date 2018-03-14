#ifndef __THREAD_H
#define __THREAD_H

#include <utility>
#include <functional>
#include <deque>
#include <memory>
#include <string>

#include "boost/thread/mutex.hpp"
#include "boost/thread/condition_variable.hpp"
#include "boost/thread/thread.hpp"
#include "boost/shared_ptr.hpp"
#include "boost/utility.hpp"

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
boost::shared_ptr<Task<Fn> > make_task(const Fn &fn)
{
	return boost::shared_ptr<Task<Fn> >(new Task<Fn>(fn));
}

class Thread;

class Task_queue: public std::deque<boost::shared_ptr<Task_base> > {
private:
	boost::mutex queue_mtx_;
	boost::condition_variable queue_cv_;

public:
	void push_task(boost::shared_ptr<Task_base> task) {
		boost::lock_guard<boost::mutex> lck(queue_mtx_);
		this->push_back(task);
        queue_cv_.notify_one();
	}	

    friend class Thread;

private:
	void swap_task_queue(std::deque<boost::shared_ptr<Task_base> > &task_queue) {
		boost::unique_lock<boost::mutex> lck(queue_mtx_);
        while (this->empty()) {
            queue_cv_.wait(lck);
        }
	    this->swap(task_queue);
	}
};

class Thread: public boost::noncopyable {
public:
    Thread(const std::string &name);
    ~Thread();

    void start();

    void stop();

    bool is_run() {
        return (thread_ ? true : false);
    }

    boost::shared_ptr<Task_queue> get_task_queue() {
        return task_queue_;
    }

private:
    void task_process();

    std::string name_;
    boost::shared_ptr<boost::thread> thread_;
    boost::shared_ptr<Task_queue> task_queue_;
};

#endif 
