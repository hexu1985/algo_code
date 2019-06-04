#ifndef RATIONAL_INC
#define RATIONAL_INC

#include <stddef.h>
#include <new>

class NextOnFreeList {
public:
	NextOnFreeList *next;
};

class Rational {
public:
	Rational(int a = 0, int b = 1): n(a), d(b) {}

	inline void *operator new(size_t size);
	inline void operator delete(void *doomed, size_t size);

	static void newMemPool() { expandTheFreeList(); }
	static void deleteMemPool();

private:
	static NextOnFreeList *freeList;	// Rational 对象的空闲列表
	static void expandTheFreeList();
	enum { EXPANSION_SIZE = 32 };

private:
	int n;	// 分子
	int d;	// 分母
};

inline
void *Rational::operator new(size_t size)
{
	if (0 == freeList) {	// 如果列表为空, 则将其填满
		expandTheFreeList();
	}

	NextOnFreeList *head = freeList;
	freeList = head->next;

	return head;
}

inline
void Rational::operator delete(void *doomed, size_t size)
{
	NextOnFreeList *head = static_cast<NextOnFreeList *>(doomed);

	head->next = freeList;
	freeList = head;
}

#endif
