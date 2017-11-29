#ifndef __search_n_h
#define __search_n_h

#include "find.h"

template <typename ForwardIterator, typename Integer, typename T>
ForwardIterator search_n(ForwardIterator first, ForwardIterator last, 
        Integer count, const T& value)
{
    if (count <= 0)
        return first;

    first = find(first, last, value);
    while (first != last) {
        Integer n = count - 1;
        ForwardIterator i = first;
        ++i;
        while (i != last && n != 0 && *i == value) {
            ++i;
            --n;
        }
        if (n == 0)
            return first;
        else
            first = find(i, last, value);
    }
    return last;
}

template <typename ForwardIterator, typename Integer, typename T, typename BinaryPredicate>
ForwardIterator search_n(ForwardIterator first, ForwardIterator last, 
        Integer count, const T& value, BinaryPredicate pred)
{
    if (count <= 0)
        return first;

    first = find(first, last, value, pred);
    while (first != last) {
        Integer n = count - 1;
        ForwardIterator i = first;
        ++i;
        while (i != last && n != 0 && pred(*i, value)) {
            ++i;
            --n;
        }
        if (n == 0)
            return first;
        else
            first = find(i, last, value, pred);
    }
    return last;
}

#endif
