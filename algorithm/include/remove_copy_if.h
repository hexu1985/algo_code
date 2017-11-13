#ifndef __remove_copy_if_h
#define __remove_copy_if_h

template <typename InputIterator, typename OutputIterator, typename UnaryPredicate>
OutputIterator remove_copy_if(InputIterator first, InputIterator last,
        OutputIterator result, UnaryPredicate pred)
{
    for ( ; first != last; ++first) {
        if (!pred(*first)) {
            *result = *first;
            ++result;
        }
    }
    return result;
}

#endif
