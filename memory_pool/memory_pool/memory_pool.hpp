#ifndef MEMORY_POOL_INC
#define MEMORY_POOL_INC

#include <stddef.h>
#include <new>

template <class T>
class MemoryPool {
public:
	MemoryPool(size_t size = EXPANSION_SIZE);
	~MemoryPool();

	// 从空闲列表中分配T元素
	inline void *alloc(size_t size);

	// 返回T元素到空闲列表中
	inline void free(void *someElement);

private:
	// 空闲列表的下一元素
	MemoryPool<T> *next;
	
	// 如果空闲列表为空, 按该大小扩展它
	enum { EXPANSION_SIZE = 32 };

	// 添加空闲元素至空闲列表
	void expandTheFreeList(int howMany = EXPANSION_SIZE);
};

template <class T>
MemoryPool<T>::MemoryPool(size_t size)
{
	expandTheFreeList(size);
}

template <class T>
MemoryPool<T>::~MemoryPool()
{
	MemoryPool<T> *nextPtr = next;
	for (nextPtr = next; nextPtr != NULL; nextPtr = next) {
		next = next->next;
		delete [] nextPtr;
	}
}

template <class T>
inline
void *MemoryPool<T>::alloc(size_t)
{
	if (!next) {
		expandTheFreeList();
	}

	MemoryPool<T> *head = next;
	next = head->next;

	return head;
}

template <class T>
inline
void MemoryPool<T>::free(void *doomed)
{
	MemoryPool<T> *head = static_cast<MemoryPool<T> *>(doomed);

	head->next = next;
	next = head;
}

template <class T>
void MemoryPool<T>::expandTheFreeList(int howMany)
{
	// 我们必须分配足够大的对象以包含下一个指针
	size_t size = (sizeof(T) > sizeof(MemoryPool<T> *)) ?
		sizeof(T) : sizeof(MemoryPool<T> *);

	MemoryPool<T> *runner = reinterpret_cast<MemoryPool<T> *>(new char[size]);

	next = runner;
	for (int i = 0; i < howMany; i++) {
		runner->next =
			reinterpret_cast<MemoryPool<T> *>(new char[size]);
		runner = runner->next;
	}
	runner->next = 0;
}

#endif
