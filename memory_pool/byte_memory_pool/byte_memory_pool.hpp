#ifndef BYTE_MEMORY_POOL_INC
#define BYTE_MEMORY_POOL_INC

#include "memory_chunk.hpp"

class ByteMemoryPool {
public:
    ByteMemoryPool(size_t initSize = 
            MemoryChunk::DEFAULT_CHUNK_SIZE);

    ~ByteMemoryPool();

    // 从私有内存池分配内存
    inline void *alloc(size_t size);

    // 释放先前从内存池中分配的内存
    inline void free(void *someElement);

private:
    // 内存块列表, 它是我们的私有存储空间
    MemoryChunk *listOfMemoryChunks;

    // 向我们的私有存储空间添加一个内存块
    void expandStorage(size_t reqSize);
};

inline void *ByteMemoryPool::alloc(size_t requestSize)
{
    size_t space = listOfMemoryChunks->spaceAvailable();
    if (space < requestSize) {
        expandStorage(requestSize);
    }

    return listOfMemoryChunks->alloc(requestSize);
}

inline void ByteMemoryPool::free(void *doomed)
{
    listOfMemoryChunks->free(doomed);
}

#endif
