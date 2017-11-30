#ifndef __search_n_if_h
#define __search_n_if_h

#include "find_if.h"

template <typename ForwardIterator, typename Integer, typename UnaryPredicate>
ForwardIterator search_n_if(ForwardIterator first, ForwardIterator last, 
        Integer count, UnaryPredicate pred)
{
    if (count <= 0)
        return first;

    first = find_if(first, last, pred);
    while (first != last) {
        Integer n = count - 1;
        ForwardIterator i = first;
        ++i;
        while (i != last && n != 0 && pred(*i)) {
            ++i;
            --n;
        }
        if (n == 0)
            return first;
        else
            first = find_if(i, last, pred);
    }
    return last;
}

#endif
