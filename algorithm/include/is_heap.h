#ifndef __is_heap_h
#define __is_heap_h

#include "heap_common.h"

template <typename RandomAccessIterator>
bool is_heap(RandomAccessIterator first, RandomAccessIterator last)
{
    auto n = last - first;
    for (auto i = 0; i <= _heap_parent(n-1); ++i) {
        auto l = _heap_left(i);
        if (l < n && first[i] < first[l]) {
            return false;
        }
        auto r = _heap_right(i);
        if (r < n && first[i] < first[r]) {
            return false;
        }
    }
    return true;
}

template <typename RandomAccessIterator, typename Compare>
bool is_heap(RandomAccessIterator first, RandomAccessIterator last,
        Compare comp)
{
    auto n = last - first;
    for (auto i = 0; i <= _heap_parent(n-1); ++i) {
        auto l = _heap_left(i);
        if (l < n && comp(first[i], first[l])) {
            return false;
        }
        auto r = _heap_right(i);
        if (r < n && comp(first[i], first[r])) {
            return false;
        }
    }
    return true;
}

#endif
