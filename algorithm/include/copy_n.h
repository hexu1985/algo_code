#ifndef __copy_n_h
#define __copy_n_h

template <typename InputIterator, typename Size, typename OutputIterator>
OutputIterator copy_n(InputIterator first, Size n, OutputIterator result)
{
    while (n > 0) {
        *result = *first;
        ++result; ++first;
        --n;
    }
    return result;
}

#endif
