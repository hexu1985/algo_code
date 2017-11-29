#ifndef __partial_sort_copy_h
#define __partial_sort_copy_h

#include "heap_common.h"
#include "make_heap.h"
#include "sort_heap.h"

template <typename InputIterator, typename RandomAccessIterator>
RandomAccessIterator partial_sort_copy(InputIterator first, InputIterator last,
                                     RandomAccessIterator result_first, RandomAccessIterator result_last)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::difference_type Distance;
    auto middle = first;
    auto result_middle = result_first;
    for ( ; middle != last && result_middle != result_last; ++middle, ++result_middle) {
        *result_middle = *middle;
    }

    make_heap(result_first, result_middle);
    for (auto i = middle ; i != last; ++i) {
        if (*i < *result_first) {
            *result_first = *i;
            _heap_heapify(result_first, Distance(0), result_middle-result_first);
        }
    }
    sort_heap(result_first, result_middle);
    return result_middle;
}

template <typename InputIterator, typename RandomAccessIterator, typename Compare>
RandomAccessIterator partial_sort_copy(InputIterator first, InputIterator last,
                                     RandomAccessIterator result_first, RandomAccessIterator result_last, Compare comp)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::difference_type Distance;
    auto middle = first;
    auto result_middle = result_first;
    for ( ; middle != last && result_middle != result_last; ++middle, ++result_middle) {
        *result_middle = *middle;
    }

    make_heap(result_first, result_middle, comp);
    for (auto i = middle ; i != last; ++i) {
        if (comp(*i, *result_first)) {
            *result_first = *i;
            _heap_heapify(result_first, Distance(0), result_middle-result_first, comp);
        }
    }
    sort_heap(result_first, result_middle, comp);
    return result_middle;
}


#endif
