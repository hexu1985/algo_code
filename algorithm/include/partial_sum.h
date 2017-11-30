#ifndef __partial_sum_h
#define __partial_sum_h

template <typename InputIterator, typename OutputIterator>
OutputIterator partial_sum(InputIterator first, InputIterator last,
        OutputIterator result)
{
    if (first == last) {
        return result;
    }

    typename std::iterator_traits<InputIterator>::value_type val = *first;
    *result = val;
    while (++first != last) {
        val = val + *first;
        *++result = val;
    }
    return ++result;
}

template <typename InputIterator, typename OutputIterator, typename BinaryOperation>
OutputIterator partial_sum(InputIterator first, InputIterator last,
        OutputIterator result, BinaryOperation binary_op)
{
    if (first == last) {
        return result;
    }

    typename std::iterator_traits<InputIterator>::value_type val = *first;
    *result = val;
    while (++first != last) {
        val = binary_op(val, *first);
        *++result = val;
    }
    return ++result;
}

#endif
