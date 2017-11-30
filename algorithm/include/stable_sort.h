#ifndef __stable_sort_h
#define __stable_sort_h

#include "insertion_sort.h"

template <typename RandomAccessIterator>
void stable_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    insertion_sort(first, last);
}

template <typename RandomAccessIterator, typename Compare>
void stable_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    insertion_sort(first, last, comp);
}

#endif

