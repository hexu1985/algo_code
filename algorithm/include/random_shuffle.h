#ifndef __random_shuffle_h
#define __random_shuffle_h

#include "iter_swap.h"

template <typename RandomAccessIterator>
void random_shuffle(RandomAccessIterator first, RandomAccessIterator last)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::difference_type Distance;
    if (first == last) return;

    for (auto i = first + 1; i != last; ++i)
        _iter_swap(i, first+Distance(rand()%(i-first+1)));
}

template <typename RandomAccessIterator, typename RandomNumberGenerator>
void random_shuffle(RandomAccessIterator first, RandomAccessIterator last, RandomNumberGenerator &gen)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::difference_type Distance;
    if (first == last) return;

    for (auto i = first + 1; i != last; ++i)
        _iter_swap(i, first+Distance(gen((i-first)+1)));
}

#endif
