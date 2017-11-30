#ifndef __max_element_h
#define __max_element_h

template <typename ForwardIterator>
ForwardIterator max_element(ForwardIterator first, ForwardIterator last)
{
    if (first == last)
        return last;

    ForwardIterator result = first;
    while (++first != last)
        if (*result < *first)
            result = first;

    return result;
}

template <typename ForwardIterator, typename Compare>
ForwardIterator max_element(ForwardIterator first, ForwardIterator last, Compare comp)
{
    if (first == last)
        return last;

    ForwardIterator result = first;
    while (++first != last)
        if (comp(*result, *first))
            result = first;

    return result;
}

#endif
