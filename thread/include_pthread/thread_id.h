#ifndef __thread_id_h
#define __thread_id_h

#include <pthread.h>
#include <iosfwd>

struct thread_id {
	pthread_t id;

	typedef	pthread_t native_handle_type;

	thread_id(): id(-1) {} 

	thread_id(pthread_t tid) { id = tid; }

	thread_id &operator =(pthread_t tid) { id = tid; return *this; }

	native_handle_type native_handle() const { return id; }

	void swap(thread_id &x)
	{
		pthread_t tid = id;
		id = x.id;
		x.id = tid;
	}
};

inline bool operator ==(const thread_id &lhs, const thread_id &rhs)
{
	return pthread_equal(lhs.id, rhs.id);
}

inline bool operator !=(const thread_id &lhs, const thread_id &rhs)
{
	return !(lhs == rhs);
}

inline bool operator <(const thread_id &lhs, const thread_id &rhs)
{
	return lhs.id < rhs.id;
}

inline bool operator <=(const thread_id &lhs, const thread_id &rhs)
{
	return !(rhs < lhs);
}

inline bool operator >(const thread_id &lhs, const thread_id &rhs)
{
	return (rhs < lhs);
}

inline bool operator >=(const thread_id &lhs, const thread_id &rhs)
{
	return !(lhs < rhs);
}

// reload operator <<, print function
template <typename charT, typename traits>
std::basic_ostream<charT, traits> &operator <<(
	std::basic_ostream<charT, traits> &os, const thread_id &id)
{
	os << id.native_handle();
	return os;
}

namespace std {

template <> struct hash<thread_id>
{
	size_t operator ()(const thread_id &id) const noexcept
	{
		return static_cast<size_t>(id.native_handle());
	}
};

}	// namespace std

#endif

