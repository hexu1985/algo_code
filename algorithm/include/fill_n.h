#ifndef __fill_n_h
#define __fill_n_h

template <typename OutputIterator, typename Size, typename T>
OutputIterator fill_n(OutputIterator first, Size n, const T &val)
{
    for ( ; n > 0; --n, ++first)
        *first = val;
    return first;
}

#endif
