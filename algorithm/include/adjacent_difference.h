#ifndef __adjacent_difference_h
#define __adjacent_difference_h

template <typename InputIterator, typename OutputIterator>
OutputIterator adjacent_difference(InputIterator first, InputIterator last, 
        OutputIterator result)
{
    if (first == last) 
        return result;

    typename std::iterator_traits<InputIterator>::value_type val, prev;
    *result = prev = *first;

    while (++first != last) {
        val = *first;
        *++result = val - prev;
        prev = val;
    }
    ++result;

    return result;
}

template <typename InputIterator, typename OutputIterator, typename BinaryOperation>
OutputIterator adjacent_difference(InputIterator first, InputIterator last,
        OutputIterator result, BinaryOperation binary_op)
{
    if (first == last) 
        return result;

    typename std::iterator_traits<InputIterator>::value_type val, prev;
    *result = prev = *first;

    while (++first != last) {
        val = *first;
        *++result = binary_op(val, prev);
        prev = val;
    }
    ++result;

    return result;
}

#endif
