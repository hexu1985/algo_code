#ifndef __min_element_h
#define __min_element_h

template <typename ForwardIterator>
ForwardIterator min_element(ForwardIterator first, ForwardIterator last)
{
    if (first == last)
        return last;

    ForwardIterator result = first;
    while (++first != last)
        if (*first < *result)
            result = first;

    return result;
}

template <typename ForwardIterator, typename Compare>
ForwardIterator min_element(ForwardIterator first, ForwardIterator last, Compare comp)
{
    if (first == last)
        return last;

    ForwardIterator result = first;
    while (++first != last)
        if (comp(*first, *result))
            result = first;

    return result;
}

#endif
