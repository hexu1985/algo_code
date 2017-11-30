#ifndef __unique_h
#define __unique_h

#include "adjacent_find.h"
#include "unique_copy.h"

template <typename ForwardIterator>
ForwardIterator unique(ForwardIterator first, ForwardIterator last)
{
    first = adjacent_find(first, last);
    return unique_copy(first, last, first);
}

template <typename ForwardIterator, typename BinaryPredicate>
ForwardIterator unique(ForwardIterator first, ForwardIterator last,
        BinaryPredicate pred)
{
    first = adjacent_find(first, last, pred);
    return unique_copy(first, last, first, pred);
}

#endif
