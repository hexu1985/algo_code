#ifndef MT_MEMORY_POOL_INC
#define MT_MEMORY_POOL_INC

template <class POOLTYPE, class LOCK>
class MTMemoryPool {
public:
    // 从freeList里分配一个元素
    inline void *alloc(size_t size);

    // 返回一个元素给freeList
    inline void free(void *someElement);

private:
    POOLTYPE stPool;    // 单线程池
    LOCK theLock;
};

template <class M, class L>
inline
void *MTMemoryPool<M, L>::alloc(size_t size)
{
    void *mem;

    theLock.lock();
    mem = stPool.alloc(size);
    theLock.unlock();

    return mem;
}

template <class M, class L>
inline
void MTMemoryPool<M, L>::free(void *doomed)
{
    theLock.lock();
    stPool.free(doomed);
    theLock.unlock();
}

#endif
