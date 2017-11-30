#ifndef __stable_partition_h
#define __stable_partition_h

#include "iter_swap.h"

template <typename BidirectionalIterator, typename UnaryPredicate>
BidirectionalIterator stable_partition(BidirectionalIterator first, BidirectionalIterator last, 
        UnaryPredicate pred)
{
    first = find_if_not(first, last, pred);
    if (first == last)
        return first;

    auto i = first;
    ++i;
    for ( ; i != last; ++i) {
        if (pred(*i)) {
            auto tmp = *i;
            auto j = i;
            --j;
            for ( ; i != first; --i, --j) {
                *i = *j;
            }
            *first = tmp;
            ++first;
        }
    }
    return first;
}

#endif
