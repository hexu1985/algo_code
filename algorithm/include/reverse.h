#ifndef __reverse_h
#define __reverse_h

#include "iter_swap.h"

template <typename RandomAccessIterator>
void _reverse(RandomAccessIterator first, RandomAccessIterator last, std::random_access_iterator_tag)
{
    while (first < last)
        _iter_swap(first++, --last);
}

template <typename BidirectionalIterator>
void _reverse(BidirectionalIterator first, BidirectionalIterator last, std::bidirectional_iterator_tag)
{
    while ((first != last) && (first != --last)) {
        _iter_swap(first, last);
        ++first;
    }
}

template <typename BidirectionalIterator>
void reverse(BidirectionalIterator first, BidirectionalIterator last)
{
    typedef typename std::iterator_traits<BidirectionalIterator>::iterator_category category;
    _reverse(first, last, category());
}

#endif
