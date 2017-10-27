#ifndef __is_sorted_until_h
#define __is_sorted_until_h

template <typename ForwardIterator>
ForwardIterator is_sorted_until(ForwardIterator first, ForwardIterator last)
{
    if (first == last)
        return first;

    auto next = first;
    while (++next != last) {
        if (*next < *first)
            return next;
        ++first;
    }
    return last;
}

template <typename ForwardIterator, typename Compare>
ForwardIterator is_sorted_until(ForwardIterator first, ForwardIterator last, Compare comp)
{
    if (first == last)
        return first;

    auto next = first;
    while (++next != last) {
        if (comp(*next, *first))
            return next;
        ++first;
    }
    return last;
}

#endif
