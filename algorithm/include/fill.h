#ifndef __fill_h
#define __fill_h

template <typename ForwardIterator, typename T>
void fill(ForwardIterator first, ForwardIterator last, const T &val)
{
    for ( ; first != last; ++first)
        *first = val;
}

#endif
