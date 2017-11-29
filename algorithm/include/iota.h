#ifndef __iota_h
#define __iota_h

template <typename ForwardIterator, typename T>
void iota(ForwardIterator first, ForwardIterator last, T value)
{
    for ( ; first != last; ++first, ++value) {
        *first = value;
    }
}

#endif
