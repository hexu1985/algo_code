#include "rational.hpp"

namespace {
    FixMemoryPool<sizeof(Rational)> *g_memPool = 0;
}

void *Rational::operator new(size_t size) 
{
    return g_memPool->alloc(size); 
}

void Rational::operator delete(void *doomed, size_t size)
{
    g_memPool->free(doomed);
}

void Rational::newMemPool() 
{
    g_memPool = new FixMemoryPool<sizeof(Rational)>(64); 
}

void Rational::deleteMemPool() 
{
    delete g_memPool; 
}

