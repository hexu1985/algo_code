#ifndef __remove_h
#define __remove_h

#include "find.h"
#include "remove_copy.h"

template <typename ForwardIterator, typename T>
ForwardIterator remove(ForwardIterator first, ForwardIterator last, const T &value)
{
    first = find(first, last, value);
    ForwardIterator next = first;
    return first == last ? first : remove_copy(++next, last, first, value);
}

#endif
