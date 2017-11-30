#ifndef __fill_h
#define __fill_h

template <typename ForwardIterator, typename T>
void fill(ForwardIterator first, ForwardIterator last, const T &value)
{
    for ( ; first != last; ++first)
        *first = value;
}

#endif
