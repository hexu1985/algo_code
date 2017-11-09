#ifndef __iota_h
#define __iota_h

template <typename ForwardIterator, typename T>
void iota(ForwardIterator first, ForwardIterator last, T val)
{
    for ( ; first != last; ++first, ++val) {
        *first = val;
    }
}

#endif
