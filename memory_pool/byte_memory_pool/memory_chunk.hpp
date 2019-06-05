#ifndef MEMORY_CHUNK_INC
#define MEMORY_CHUNK_INC

#include <stddef.h>
#include <new>

class MemoryChunk {
public:
    MemoryChunk(MemoryChunk *nextChunk, size_t chunkSize);
    ~MemoryChunk();

    inline void *alloc(size_t size);
    inline void free(void *someElement);

    // 指向列表下一内存块的指针
    MemoryChunk *nextMemChunk() { return next; }

    // 当前内存块剩余空间大小
    size_t spaceAvailable()
    {
        return chunkSize - bytesAlreadyAllocated;
    }

    // 这是一个内存块的默认大小
    enum { DEFAULT_CHUNK_SIZE = 4096 };

private:
    MemoryChunk *next;
    char *mem;

    // 一个内存块的大小
    size_t chunkSize;

    // 当前内存块中已分配的字节数
    size_t bytesAlreadyAllocated;
};

inline void *MemoryChunk::alloc(size_t requestSize)
{
    void *addr = static_cast<void *>
        (static_cast<char *>(mem) + bytesAlreadyAllocated);
    bytesAlreadyAllocated += requestSize;

    return addr;
}

inline void MemoryChunk::free(void *doomed) {}

#endif
