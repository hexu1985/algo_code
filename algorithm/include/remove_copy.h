#ifndef __remove_copy_h
#define __remove_copy_h

template <typename ForwardIterator, typename OutputIterator, typename T>
OutputIterator remove_copy(ForwardIterator first, ForwardIterator last, 
        OutputIterator result, const T &value)
{
    for ( ; first != last; ++first) {
        if (*first != value) {
            *result = *first;
            ++result;
        }
    }

    return result;
}

#endif
