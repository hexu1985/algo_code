#ifndef __replace_copy_if_h
#define __replace_copy_if_h

template <typename InputIterator, typename OutputIterator, typename UnaryPredicate, typename T>
OutputIterator replace_copy_if(InputIterator first, InputIterator last,
        OutputIterator result, UnaryPredicate pred, const T& new_value)
{
    for ( ; first != last; ++first, ++result)
        *result = pred(*first) ? new_value : *first;
    return result;
}

#endif
