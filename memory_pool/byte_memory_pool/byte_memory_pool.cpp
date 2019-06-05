#include "byte_memory_pool.hpp"

// 创建ByteMemoryPool对象, 生成私有存储空间
ByteMemoryPool::ByteMemoryPool(size_t initSize)
{
    expandStorage(initSize);
}

ByteMemoryPool::~ByteMemoryPool()
{
    MemoryChunk *memChunk = listOfMemoryChunks;

    while (memChunk) {
        listOfMemoryChunks = memChunk->nextMemChunk();
        delete memChunk;
        memChunk = listOfMemoryChunks;
    }
}

void ByteMemoryPool::expandStorage(size_t reqSize)
{
    listOfMemoryChunks = new MemoryChunk(listOfMemoryChunks, reqSize);
}
