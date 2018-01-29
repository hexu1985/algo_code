#ifndef __this_thread_h
#define __this_thread_h

#include <pthread.h>
#include <chrono>
#include "thread_id.h"

namespace this_thread {

inline thread_id get_id() noexcept
{
	return thread_id(pthread_self());
}

inline void yield() noexcept
{
	sched_yield();
}

inline void sleep_impl(const struct timespec &ts)
{
	struct timespec trq = ts, trm;
	while (true) {
		if (nanosleep(&trq, &trm) == 0)
			break;
		else if (errno == EINTR)
			trq = trm;
		else
			throw std::system_error(errno, std::system_category(), __func__);
	}
}

template <typename Rep, typename Period>
void sleep_for(const std::chrono::duration<Rep, Period> &rel_time)
{
	if (rel_time.count() <= 0)
		return;

	struct timespec ts;
	std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(rel_time);
	ts.tv_sec = sec.count();
	ts.tv_nsec = std::chrono::duration_cast<std::chrono::nanoseconds>(rel_time - sec).count();

    sleep_impl(ts);
}

template <typename Clock, typename Duration>
void sleep_until(const std::chrono::time_point<Clock, Duration> &abs_time)
{
	Duration rel_time = abs_time - Clock::now();
	sleep_for(rel_time);
}

}	// namespace this_thread

#endif
