#ifndef __replace_copy_h
#define __replace_copy_h

template <typename InputIterator, typename OutputIterator, typename T>
OutputIterator replace_copy(InputIterator first, InputIterator last, OutputIterator result, 
        const T& old_value, const T& new_value)
{
    for ( ; first != last; ++first, ++result)
        *result = (*first == old_value) ? new_value : *first;
    return result;
}

#endif
