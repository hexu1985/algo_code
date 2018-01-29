#ifndef __thread_h
#define __thread_h

#include <errno.h>
#include <memory>
#include <functional>
#include <system_error>

#include "thread_id.h"
#include "this_thread.h"

class thread {
private:
	thread_id id_;

public:
	typedef	thread_id id;
	typedef	id::native_handle_type native_handle_type;

	thread() {}

private:
	thread(const thread &) = delete;
	thread &operator =(const thread &) = delete; 

public:
	template <typename Fn, typename ...Args>
	explicit thread(Fn &&fn, Args &&...args)
	{
		create_thread(
                make_runable(
                    std::bind(std::forward<Fn>(fn), std::forward<Args>(args)...)));
	}

	thread(thread &&x) noexcept: id_(x.id_) 
	{
		x.id_ = id(); 
	}

	thread &operator =(thread &&rhs)
	{
		if (&rhs == this) {
			return *this;
		}

		if (joinable()) {
			std::terminate();
		}

		id_ = rhs.id_;
		rhs.id_ = id();

		return *this;
	}

	~thread() 
	{
		if (joinable()) {
			std::terminate(); 
		}
	}

	bool joinable() const { return (id_ != id()); }

	id get_id() const { return id_; }

	native_handle_type native_handle() const { return id_.native_handle(); }

	void join()
	{
		if (!joinable()) {
			throw std::system_error(EINVAL, std::system_category(), __func__);
		}

		int err = pthread_join(id_.native_handle(), NULL);
		if (err != 0) {
			throw std::system_error(err, std::system_category(), __func__);
		}
		id_ = id();
	}

	void detach()
	{
		if (!joinable()) {
			throw std::system_error(EINVAL, std::system_category(), __func__);
		}

		int err = pthread_detach(id_.native_handle());
		if (err != 0) {
			throw std::system_error(err, std::system_category(), __func__);
		}

		id_ = id();
	}

	void swap(thread &x) { id_.swap(x.id_); }

private:
	struct runable_base {
		virtual ~runable_base() {}
		virtual void run() = 0;
	};

	template <typename Fn>
	struct runable: public runable_base {
		Fn fn;

		runable(Fn &&fn): fn(std::forward<Fn>(fn)) {}

        ~runable() override {}
		void run() override { fn(); }
	};

	template <typename Fn>
	runable<Fn> *make_runable(Fn &&fn)
	{
		return new runable<Fn>(std::forward<Fn>(fn));
	}

	void create_thread(runable_base *r)
	{
		pthread_t tid;
		int err = pthread_create(&tid, NULL, &thread_routine, r);
		if (err != 0) {
			delete r;
			throw std::system_error(err, std::system_category(), __func__);
		}
		id_ = tid;
	}

	static void *thread_routine(void *arg)
	{
		// run thread runable
        std::unique_ptr<runable_base> r(reinterpret_cast<runable_base *>(arg));
        r->run();
		return NULL;
	}
};

/**
 * Specializes the std::swap algorithm for thread. 
 * Exchanges the state of lhs with that of rhs. 
 * Effectively calls lhs.swap(rhs). 
 */
inline 
void swap(thread &a, thread &b) noexcept
{
	a.swap(b);
}

#endif

