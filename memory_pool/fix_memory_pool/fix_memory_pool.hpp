#ifndef FIX_MEMORY_POOL_INC
#define FIX_MEMORY_POOL_INC

#include <stddef.h>
#include <new>

template <size_t N>
class FixMemoryPool {
public:
	FixMemoryPool(size_t size = EXPANSION_SIZE);
	~FixMemoryPool();

	// 从空闲列表中分配N元素
	inline void *alloc(size_t size);

	// 返回N元素到空闲列表中
	inline void free(void *someElement);

private:
    struct MemoryChunk {
        MemoryChunk *next;
    };

    size_t expansionSize_;
    MemoryChunk *chunkList_ = nullptr;    // 空闲列表的下一元素
	
	// 如果空闲列表为空, 按该大小扩展它
	enum { EXPANSION_SIZE = 32 };

	// 添加空闲元素至空闲列表
	void expandTheFreeList(int howMany = EXPANSION_SIZE);
};

template <size_t N>
FixMemoryPool<N>::FixMemoryPool(size_t size): 
    expansionSize_(size),
    chunkList_(nullptr)
{
	expandTheFreeList(expansionSize_);
}

template <size_t N>
FixMemoryPool<N>::~FixMemoryPool()
{
	for (MemoryChunk *nextPtr = chunkList_; chunkList_ != nullptr; nextPtr = chunkList_) {
		chunkList_ = chunkList_->next;
		delete [] nextPtr;
	}
}

template <size_t N>
inline
void *FixMemoryPool<N>::alloc(size_t)
{
	if (!chunkList_) {
		expandTheFreeList(expansionSize_);
	}

	MemoryChunk *head = chunkList_;
	chunkList_ = head->next;

	return head;
}

template <size_t N>
inline
void FixMemoryPool<N>::free(void *doomed)
{
	MemoryChunk *head = static_cast<MemoryChunk *>(doomed);

	head->next = chunkList_;
	chunkList_ = head;
}

template <size_t N>
void FixMemoryPool<N>::expandTheFreeList(int howMany)
{
	// 我们必须分配足够大的对象以包含下一个指针
	size_t size = (N > sizeof(MemoryChunk *)) ?
		N : sizeof(MemoryChunk *);

	MemoryChunk *runner = reinterpret_cast<MemoryChunk *>(new char[size]);

	chunkList_ = runner;
	for (int i = 0; i < howMany; i++) {
		runner->next =
			reinterpret_cast<MemoryChunk *>(new char[size]);
		runner = runner->next;
	}
	runner->next = nullptr;
}

#endif
