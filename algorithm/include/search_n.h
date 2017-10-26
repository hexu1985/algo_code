#ifndef __search_n_h
#define __search_n_h

#include "find.h"

template <typename ForwardIterator, typename Integer, typename T>
ForwardIterator search_n(ForwardIterator first, ForwardIterator last, 
        Integer count, const T& val)
{
    if (count <= 0)
        return first;

    first = find(first, last, val);
    while (first != last) {
        Integer n = count - 1;
        ForwardIterator i = first;
        ++i;
        while (i != last && n != 0 && *i == val) {
            ++i;
            --n;
        }
        if (n == 0)
            return first;
        else
            first = find(i, last, val);
    }
    return last;
}

template <typename ForwardIterator, typename Integer, typename T, typename BinaryPredicate>
ForwardIterator search_n(ForwardIterator first, ForwardIterator last, 
        Integer count, const T& val, BinaryPredicate pred)
{
    if (count <= 0)
        return first;

    first = find(first, last, val, pred);
    while (first != last) {
        Integer n = count - 1;
        ForwardIterator i = first;
        ++i;
        while (i != last && n != 0 && pred(*i, val)) {
            ++i;
            --n;
        }
        if (n == 0)
            return first;
        else
            first = find(i, last, val, pred);
    }
    return last;
}

#endif
