#ifndef __make_heap_h
#define __make_heap_h

#include "heap_common.h"

template <typename RandomAccessIterator>
void make_heap(RandomAccessIterator first, RandomAccessIterator last)
{
    auto n = last-first;
    for (auto i = _heap_parent(n-1); i >= 0; --i) {
        _heap_heapify(first, i, n);
    }
}

template <typename RandomAccessIterator, typename Compare>
void make_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    auto n = last - first;
    for (auto i = _heap_parent(n-1); i >= 0; --i) {
        _heap_heapify(first, i, n, comp);
    }
}

#endif
