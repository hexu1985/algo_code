#ifndef __is_heap_until_h
#define __is_heap_until_h

#include "heap_common.h"

template <typename RandomAccessIterator>
RandomAccessIterator is_heap_until(RandomAccessIterator first, RandomAccessIterator last)
{
    auto n = last - first;
    for (auto i = 0; i <= _heap_parent(n-1); ++i) {
        auto l = _heap_left(i);
        if (l < n && first[i] < first[l]) {
            return first+l;
        }
        auto r = _heap_right(i);
        if (r < n && first[i] < first[r]) {
            return first+r;
        }
    }
    return last;
}

template <typename RandomAccessIterator, typename Compare>
RandomAccessIterator is_heap_until(RandomAccessIterator first, RandomAccessIterator last,
        Compare comp)
{
    auto n = last - first;
    for (auto i = 0; i <= _heap_parent(n-1); ++i) {
        auto l = _heap_left(i);
        if (l < n && comp(first[i], first[l])) {
            return first+i;
        }
        auto r = _heap_right(i);
        if (r < n && comp(first[i], first[r])) {
            return first+i;
        }
    }
    return last;
}

#endif

