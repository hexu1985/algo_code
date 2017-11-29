#ifndef __binary_search_h
#define __binary_search_h

#include "lower_bound.h"

template <typename ForwardIterator, typename T>
bool binary_search(ForwardIterator first, ForwardIterator last, const T& value)
{
    auto i = _lower_bound(first, last, value);
    return (i != last && !(value < *i));
}

template <typename ForwardIterator, typename T, typename Compare>
bool binary_search(ForwardIterator first, ForwardIterator last, const T& value, Compare comp)
{
    auto i = _lower_bound(first, last, value, comp);
    return (i != last && !comp(value, *i));
}

#endif
