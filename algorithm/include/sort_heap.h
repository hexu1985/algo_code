#ifndef __sort_heap_h
#define __sort_heap_h

#include "pop_heap.h"

template <typename RandomAccessIterator>
void sort_heap(RandomAccessIterator first, RandomAccessIterator last)
{
    while (last - first > 1)
        pop_heap(first, last--);
}

template <typename RandomAccessIterator, typename Compare>
void sort_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    while (last - first > 1)
        pop_heap(first, last--, comp);
}

#endif
