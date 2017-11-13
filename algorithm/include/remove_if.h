#ifndef __remove_if_h
#define __remove_if_h

template <typename ForwardIterator, typename UnaryPredicate>
ForwardIterator remove_if(ForwardIterator first, ForwardIterator last,
        UnaryPredicate pred)
{
    first = find_if(first, last, pred);
    ForwardIterator next = first;
    return first == last ? first : remove_copy_if(++next, last, first, pred);
}

#endif
