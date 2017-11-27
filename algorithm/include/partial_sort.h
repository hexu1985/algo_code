#ifndef __partial_sort_h
#define __partial_sort_h

#include "iter_swap.h"
#include "heap_common.h"
#include "make_heap.h"
#include "sort_heap.h"

template <class RandomAccessIterator>
void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::difference_type Distance;
    make_heap(first, middle);
    for (auto i = middle; i < last; ++i) {
        if (*i < *first) {
            _iter_swap(i, first);
            _heap_heapify(first, Distance(0), middle-first);
        }
    }
    sort_heap(first, middle);
}

template <class RandomAccessIterator, class Compare>
void partial_sort(RandomAccessIterator first, RandomAccessIterator middle, 
        RandomAccessIterator last, Compare comp)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::difference_type Distance;
    make_heap(first, middle, comp);
    for (auto i = middle; i < last; ++i) {
        if (comp(*i, *first)) {
            _iter_swap(i, first);
            _heap_heapify(first, Distance(0), middle-first, comp);
        }
    }
    sort_heap(first, middle, comp);
}

#endif
