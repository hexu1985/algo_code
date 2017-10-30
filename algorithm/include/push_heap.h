#ifndef __push_heap_h
#define __push_heap_h

#include "heap_common.h"

template <typename RandomAccessIterator>
void push_heap(RandomAccessIterator first, RandomAccessIterator last)
{
    auto i = (last - first) - 1;
    while (i > 0 && first[_heap_parent(i)] < first[i]) {
        std::iter_swap(first+_heap_parent(i), first+i);
        i = _heap_parent(i);
    }
}

template <typename RandomAccessIterator, typename Compare>
void push_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    auto i = (last - first) - 1;
    while (i > 0 && comp(first[_heap_parent(i)], first[i])) {
        std::iter_swap(first+_heap_parent(i), first+i);
        i = _heap_parent(i);
    }
}

#endif
