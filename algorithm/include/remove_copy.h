#ifndef __remove_copy_h
#define __remove_copy_h

template <typename ForwardIterator, typename OutputIterator, typename T>
OutputIterator remove_copy(ForwardIterator first, ForwardIterator last, 
        OutputIterator result, const T &val)
{
    for ( ; first != last; ++first) {
        if (*first != val) {
            *result = *first;
            ++result;
        }
    }

    return result;
}

#endif
