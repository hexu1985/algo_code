#ifndef __rotate_h
#define __rotate_h

#include "iter_swap.h"
#include "reverse.h"

template <typename ForwardIterator>
void _rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last, std::forward_iterator_tag)
{
    for (ForwardIterator i = middle; ; ) {
        _iter_swap(first, i);
        ++first;
        ++i;

        if (first == middle) {
            if (i == last) return;
            middle = i;
        } else if (i == last) {
            i = middle;
        }
    }
}

template <typename ForwardIterator>
void _rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last, std::bidirectional_iterator_tag)
{
    reverse(first, middle);
    reverse(middle, last);
    reverse(first, last);
}

template <typename ForwardIterator>
void rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last)
{
    typedef typename std::iterator_traits<ForwardIterator>::iterator_category category;
    if (first == middle || middle == last) return;
    _rotate(first, middle, last, category());
}

#endif
