#ifndef RATIONAL_INC
#define RATIONAL_INC

#include "dummy_lock.hpp"
#include "memory_pool.hpp"
#include "mt_memory_pool.hpp"

class Rational {
public:
	Rational(int a = 0, int b = 1): n(a), d(b) {}

	void *operator new(size_t size) { return memPool->alloc(size); }
	void operator delete(void *doomed, size_t size)
	{
		memPool->free(doomed);
	}

	static void newMemPool() { memPool = new MTMemoryPool<MemoryPool<Rational>, DummyLock>; }
	static void deleteMemPool() { delete memPool; }

private:
	static MTMemoryPool<MemoryPool<Rational>, DummyLock> *memPool;

private:
	int n;	// 分子
	int d;	// 分母
};

#endif