#ifndef __thread_h
#define __thread_h

#include <assert.h>
#include <utility>
#include <functional>
#include <deque>
#include <mutex>
#include <condition_variable>
#include <thread>
#include <atomic>
#include <memory>
#include <string>

struct Task_base {
    virtual ~Task_base() {}
    virtual void run() = 0;
};

template <typename Fn>
struct Task: public Task_base {
    Task(Fn &&fn): f_(std::forward<Fn>(fn)) {}

    virtual void run() { f_(); }

    Fn f_;
};

struct NullTask: public Task_base {
    virtual void run() {}
};

    template <typename Fn>
std::shared_ptr<Task<Fn>> make_task_aux(Fn &&fn)
{
    return std::make_shared<Task<Fn>>(std::forward<Fn>(fn));
}

    template <typename ...Args>
std::shared_ptr<Task_base> make_task(Args &&...args)
{
    return make_task_aux(std::bind(std::forward<Args>(args)...));
}

class Thread;

class Task_queue: public std::deque<std::shared_ptr<Task_base>> {
    private:
        std::mutex queue_mtx_;
        std::condition_variable queue_cv_;
        std::atomic<bool> cancel_flag_{false};

    public:
        void push_task(std::shared_ptr<Task_base> task) {
            std::lock_guard<std::mutex> lck(queue_mtx_);
            this->push_back(task);
            queue_cv_.notify_one();
        }

        void request_cancel() {
            cancel_flag_ = true;
            push_task(std::make_shared<NullTask>());
        }

        friend class Thread;

    private:
        void swap_task_queue(std::deque<std::shared_ptr<Task_base>> &task_queue, bool &has_cancel_request) {
            std::unique_lock<std::mutex> lck(queue_mtx_);
            while (this->empty()) {
                queue_cv_.wait(lck);
            }
            this->swap(task_queue);
            has_cancel_request = cancel_flag_;
        }
};

class Thread {
    private:
        std::string name_;
        std::shared_ptr<std::thread> thread_;
        std::shared_ptr<Task_queue> task_queue_;

    public:
        Thread(const std::string &name = "");
        ~Thread();

        Thread(Thread &&x): name_(std::move(x.name_)), 
        thread_(std::move(x.thread_)),
        task_queue_(std::move(x.task_queue_))
    {
        assert(x.name_.empty());
        assert(x.thread_ == nullptr);
        assert(x.task_queue_ == nullptr);
    }

        Thread &operator =(Thread &&rhs)
        {
            if (&rhs == this) {
                return *this;
            }

            if (is_run()) {
                std::terminate();
            }

            name_ = std::move(rhs.name_);
            thread_ = std::move(rhs.thread_);
            task_queue_ = std::move(rhs.task_queue_);

            assert(rhs.name_.empty());
            assert(rhs.thread_ == nullptr);
            assert(rhs.task_queue_ == nullptr);

            return *this;
        }

        void start();

        void stop();

        bool is_run() {
            return (thread_ ? true : false);
        }

        std::shared_ptr<Task_queue> get_task_queue() {
            return task_queue_;
        }

        const std::string &name() const {
            return name_;
        }

        void set_name(const std::string &name) {
            name_ = name;
        }

    private:
        Thread(const Thread &) = delete;
        void operator =(const Thread &) = delete;

        void task_process();
};

#endif 
