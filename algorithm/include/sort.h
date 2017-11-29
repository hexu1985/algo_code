#ifndef __sort_h
#define __sort_h

#include "iter_swap.h"
#include "insertion_sort.h"

template <typename T>
const T &_median(const T &a, const T &b, const T &c)
{
    if (a < b) {
        if (b < c)  // a < b < c
            return b;
        else if (c < a) // c < a < b
            return a;
        else
            return c;
    } else {    // b < a
        if (a < c)  // b < a < c
            return a;
        else if (c < b) // c < b < a
            return b;
        else
            return c;
    }
}

template <typename RandomAccessIterator, typename T>
RandomAccessIterator _unduarded_partition(RandomAccessIterator first, RandomAccessIterator last, T pivot)
{
    while (true) {
        while (*first < pivot) ++first;

        do {
            --last;
        } while (pivot < *last);

        if (!(first < last))
            return first;

        _iter_swap(first, last);
        ++first;
    }
}

template <typename RandomAccessIterator>
void sort(RandomAccessIterator first, RandomAccessIterator last)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    if (last - first < 3) {
        insertion_sort(first, last);
    } else {
        auto cut = _unduarded_partition(first, last, 
                T(_median(*first, *(first+(last-first)/2), *(last-1))));
        sort(first, cut);
        sort(cut, last);
    }
}

template <typename T, typename Compare>
const T &_median(const T &a, const T &b, const T &c, Compare comp)
{
    if (comp(a, b)) {
        if (comp(b, c))  // a < b < c
            return b;
        else if (comp(c, a)) // c < a < b
            return a;
        else
            return c;
    } else {    // b < a
        if (comp(a, c))  // b < a < c
            return a;
        else if (comp(c, b)) // c < b < a
            return b;
        else
            return c;
    }
}

template <typename RandomAccessIterator, typename T, typename Compare>
RandomAccessIterator _unduarded_partition(RandomAccessIterator first, RandomAccessIterator last, T pivot, Compare comp)
{
    while (true) {
        while (comp(*first, pivot)) ++first;

        do {
            --last;
        } while (comp(pivot, *last));

        if (!(first < last))
            return first;

        _iter_swap(first, last);
        ++first;
    }
}

template <typename RandomAccessIterator, typename Compare>
void sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    if (last - first < 3) {
        insertion_sort(first, last, comp);
    } else {
        auto cut = _unduarded_partition(first, last, 
                T(_median(*first, *(first+(last-first)/2), *(last-1), comp)), comp);
        sort(first, cut, comp);
        sort(cut, last, comp);
    }
}

#endif
