#ifndef __pop_heap_h
#define __pop_heap_h

#include "heap_common.h"
#include "iter_swap.h"

template <typename RandomAccessIterator>
void pop_heap(RandomAccessIterator first, RandomAccessIterator last)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::difference_type Distance;
    if (first < --last) {
        _iter_swap(first, last);
        _heap_heapify(first, Distance(0), last-first);
    }
}

template <typename RandomAccessIterator, typename Compare>
void pop_heap(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::difference_type Distance;
    if (first < --last) {
        _iter_swap(first, last);
        _heap_heapify(first, Distance(0), last-first, comp);
    }
}

#endif
