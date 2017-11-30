#ifndef __copy_if_h
#define __copy_if_h

template <typename InputIterator, typename OutputIterator, typename UnaryPredicate>
OutputIterator copy_if(InputIterator first, InputIterator last, 
        OutputIterator result, UnaryPredicate pred)
{
    while (first!=last) {
        if (pred(*first)) {
            *result = *first;
            ++result;
        }
        ++first;
    }
    return result;
}

#endif
