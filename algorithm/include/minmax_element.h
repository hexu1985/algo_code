#ifndef __minmax_element_h
#define __minmax_element_h

template <typename ForwardIterator>
std::pair<ForwardIterator, ForwardIterator> minmax_element(ForwardIterator first, ForwardIterator last)
{
    if (first == last)
        return std::make_pair(last, last);

    ForwardIterator least = first;
    ForwardIterator largest = first;
    while (++first != last) {
        if (*first < *least)
            least = first;
        if (*largest < *first)
            largest = first;
    }

    return std::make_pair(least, largest);
}

template <typename ForwardIterator, typename Compare>
std::pair<ForwardIterator, ForwardIterator> minmax_element(ForwardIterator first, ForwardIterator last, Compare comp)
{
    if (first == last)
        return std::make_pair(last, last);

    ForwardIterator least = first;
    ForwardIterator largest = first;
    while (++first != last) {
        if (comp(*first, *least))
            least = first;
        if (comp(*largest, *first))
            largest = first;
    }

    return std::make_pair(least, largest);
}

#endif
