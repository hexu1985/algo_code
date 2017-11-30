#ifndef __nth_element_h
#define __nth_element_h

#include "insertion_sort.h"
#include "sort.h"

template <typename RandomAccessIterator>
void nth_element(RandomAccessIterator first, RandomAccessIterator nth, 
        RandomAccessIterator last)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    while (last - first > 3) {
        auto cut = _unduarded_partition(first, last, 
                T(_median(*first, *(first+(last-first)/2), *(last-1))));
        if (cut <= nth)
            first = cut;
        else
            last = cut;
    }
    insertion_sort(first, last);
}

template <typename RandomAccessIterator, typename Compare>
void nth_element(RandomAccessIterator first, RandomAccessIterator nth, 
        RandomAccessIterator last, Compare comp)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    while (last - first > 3) {
        auto cut = _unduarded_partition(first, last, 
                T(_median(*first, *(first+(last-first)/2), *(last-1), comp)), comp);
        if (cut <= nth)
            first = cut;
        else
            last = cut;
    }
    insertion_sort(first, last, comp);
}

#endif
