#ifndef __copy_h
#define __copy_h

template <typename InputIterator, typename OutputIterator>
OutputIterator _copy(InputIterator first, InputIterator last, OutputIterator result)
{
    while (first!=last) {
        *result = *first;
        ++result; ++first;
    }
    return result;
}

template <typename InputIterator, typename OutputIterator>
OutputIterator copy(InputIterator first, InputIterator last, OutputIterator result)
{
    return _copy(first, last, result);
}

#endif
