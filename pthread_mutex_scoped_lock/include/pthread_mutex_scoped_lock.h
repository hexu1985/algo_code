#ifndef BOOST_PTHREAD_MUTEX_SCOPED_LOCK_HPP
#define BOOST_PTHREAD_MUTEX_SCOPED_LOCK_HPP
//  (C) Copyright 2007-8 Anthony Williams
//
//  Distributed under the Boost Software License, Version 1.0. (See
//  accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

#include <pthread.h>
#include <assert.h>

namespace HX {	

class pthread_mutex_scoped_lock {
private:
	pthread_mutex_t *m;
	bool locked;

    void check_ret(int ret)
    {
        assert(!ret);
        (void) ret;
    }

public:
	explicit pthread_mutex_scoped_lock(pthread_mutex_t* m_) throw():
		m(m_),locked(true)
	{
		check_ret(pthread_mutex_lock(m));
	}

	void unlock() throw()
	{
		check_ret(pthread_mutex_unlock(m));
		locked=false;
	}

	void unlock_if_locked() throw()
	{
		if(locked)
		{
			unlock();
		}
	}

	~pthread_mutex_scoped_lock() throw()
	{
		if(locked)
		{
			unlock();
		}
	}

};

class pthread_mutex_scoped_unlock {
private:
	pthread_mutex_t* m;

    void check_ret(int ret)
    {
        assert(!ret);
        (void) ret;
    }

public:
    pthread_mutex_scoped_unlock(pthread_mutex_t* m_) throw():
        m(m_)
    {
        check_ret(pthread_mutex_unlock(m));
    }

    ~pthread_mutex_scoped_unlock() throw()
    {
        check_ret(!pthread_mutex_lock(m));
    }
};

}	// namespace HX

#endif

