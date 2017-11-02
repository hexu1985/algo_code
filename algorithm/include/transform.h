#ifndef __transform_h
#define __transform_h

template <typename InputIterator, typename OutputIterator, typename UnaryOperator>
OutputIterator transform(InputIterator first1, InputIterator last1,
        OutputIterator result, UnaryOperator op)
{
    while (first1 != last1) {
        *result = op(*first1);
        ++result; ++first1;
    }
    return result;
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename BinaryOperation>
OutputIterator transform(InputIterator1 first1, InputIterator1 last1, 
        InputIterator2 first2, OutputIterator result, BinaryOperation binary_op)
{
    while (first1 != last1) {
        *result = binary_op(*first1, *first2);
        ++result; ++first1; ++first2;
    }
    return result;
}

#endif
