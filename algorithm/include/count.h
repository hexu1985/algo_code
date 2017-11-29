#ifndef __count_h
#define __count_h

template <typename InputIterator, typename T>
typename std::iterator_traits<InputIterator>::difference_type count(InputIterator first, InputIterator last, 
        const T& value)
{
    typename std::iterator_traits<InputIterator>::difference_type n = 0;
    for ( ; first != last; ++first)
        if (*first == value)
            ++n;
    return n;
}

template <typename InputIterator, typename T, typename BinaryPredicate>
typename std::iterator_traits<InputIterator>::difference_type count(InputIterator first, InputIterator last, 
        const T& value, BinaryPredicate pred)
{
    typename std::iterator_traits<InputIterator>::difference_type n = 0;
    for ( ; first != last; ++first)
        if (pred(*first, value))
            ++n;
    return n;
}

#endif
