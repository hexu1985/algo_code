#ifndef __upper_bound_h
#define __upper_bound_h

template <typename ForwardIterator, typename T>
ForwardIterator _upper_bound(ForwardIterator first, ForwardIterator last, const T &value, 
        std::forward_iterator_tag)
{
    auto len = std::distance(first, last);

    while (len > 0) {
        auto half = len/2;
        auto middle = first;
        std::advance(middle, half);
        if (value < *middle) {
            len = half;
        } else {    // *middle <= value
            first = middle;
            ++first;
            len = len - half - 1;
        }
    }
    return first;
}

template <typename RandomAccessIterator, typename T>
RandomAccessIterator _upper_bound(RandomAccessIterator first, RandomAccessIterator last, const T &value, 
        std::random_access_iterator_tag)
{
    auto len = last - first;

    while (len > 0) {
        auto half = len/2;
        auto middle = first + half;
        if (value < *middle) {
            len = half;
        } else {    // *middle <= value
            first = middle + 1;
            len = len - half - 1;
        } 
    }
    return first;
}

template <typename ForwardIterator, typename T>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, const T &value)
{
    typedef typename std::iterator_traits<ForwardIterator>::iterator_category category;
    return _upper_bound(first, last, value, category());
}

template <typename ForwardIterator, typename T, typename Compare>
ForwardIterator _upper_bound(ForwardIterator first, ForwardIterator last, const T &value, Compare comp, 
        std::forward_iterator_tag)
{
    auto len = std::distance(first, last);

    while (len > 0) {
        auto half = len/2;
        auto middle = first;
        std::advance(middle, half);
        if (comp(value, *middle)) {
            len = half;
        } else {    // *middle <= value
            first = middle;
            ++first;
            len = len - half - 1;
        }
    }
    return first;
}

template <typename RandomAccessIterator, typename T, typename Compare>
RandomAccessIterator _upper_bound(RandomAccessIterator first, RandomAccessIterator last, const T &value, Compare comp, 
        std::random_access_iterator_tag)
{
    auto len = last - first;

    while (len > 0) {
        auto half = len/2;
        auto middle = first + half;
        if (comp(value, *middle)) {
            len = half;
        } else {    // *middle <= value
            first = middle + 1;
            len = len - half - 1;
        } 
    }
    return first;
}

template <typename ForwardIterator, typename T, typename Compare>
ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, const T &value, Compare comp)
{
    typedef typename std::iterator_traits<ForwardIterator>::iterator_category category;
    return _upper_bound(first, last, value, comp, category());
}

#endif
