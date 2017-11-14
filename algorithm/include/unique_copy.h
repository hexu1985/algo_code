#ifndef __unique_copy_h
#define __unique_copy_h

template <typename InputIterator, typename ForwardIterator>
ForwardIterator _unique_copy(InputIterator first, InputIterator last,
        ForwardIterator result, std::forward_iterator_tag)
{
    *result = *first;
    while (++first != last)
        if (*result != *first) *++result = *first;
    return ++result;
}

template <typename InputIterator, typename ForwardIterator, typename BinaryPredicate>
ForwardIterator _unique_copy(InputIterator first, InputIterator last,
        ForwardIterator result, BinaryPredicate pred, std::forward_iterator_tag)
{
    *result = *first;
    while (++first != last)
        if (!pred(*result, *first)) *++result = *first;
    return ++result;
}

template <typename InputIterator, typename OutputIterator>
OutputIterator _unique_copy(InputIterator first, InputIterator last,
        OutputIterator result, std::output_iterator_tag)
{
    auto value = *first;
    *result = value;
    while (++first != last)
        if (value != *first) {
            value = *first;
            *++result = value;
        }
    return ++result;
}

template <typename InputIterator, typename OutputIterator, typename BinaryPredicate>
OutputIterator _unique_copy(InputIterator first, InputIterator last,
        OutputIterator result, BinaryPredicate pred, std::output_iterator_tag)
{
    auto value = *first;
    *result = value;
    while (++first != last)
        if (pred(value, *first)) {
            value = *first;
            *++result = value;
        }
    return ++result;
}

template <typename InputIterator, typename OutputIterator>
OutputIterator unique_copy(InputIterator first, InputIterator last,
        OutputIterator result)
{
    if (first == last) return result;

    typedef typename std::iterator_traits<OutputIterator>::iterator_category category;
    return _unique_copy(first, last, result, category());
}

template <typename InputIterator, typename OutputIterator, typename BinaryPredicate>
OutputIterator unique_copy(InputIterator first, InputIterator last,
        OutputIterator result, BinaryPredicate pred)
{
    if (first == last) return result;

    typedef typename std::iterator_traits<OutputIterator>::iterator_category category;
    return _unique_copy(first, last, result, pred, category());
}

#endif
