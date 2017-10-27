#ifndef __sort_h
#define __sort_h

#include "quick_sort.h"

template <typename RandomAccessIterator>
void sort(RandomAccessIterator first, RandomAccessIterator last)
{
    quick_sort(first, last);
}

template <typename RandomAccessIterator, typename Compare>
void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    quick_sort(first, last, comp);
}

#endif
