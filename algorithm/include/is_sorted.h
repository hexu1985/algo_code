#ifndef __is_sorted_h
#define __is_sorted_h

template <typename ForwardIterator>
bool is_sorted(ForwardIterator first, ForwardIterator last)
{
    if (first == last)
        return true;

    auto next = first;
    while (++next != last) {
        if (*next < *first)
            return false;
        ++first;
    }
    return true;
}

template <typename ForwardIterator, typename Compare>
bool is_sorted(ForwardIterator first, ForwardIterator last, Compare comp)
{
    if (first == last)
        return true;

    auto next = first;
    while (++next != last) {
        if (comp(*next, *first))
            return false;
        ++first;
    }
    return true;
}

#endif
