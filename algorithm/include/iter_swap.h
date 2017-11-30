#ifndef __iter_swap_h
#define __iter_swap_h

template <typename ForwardIterator1, typename ForwardIterator2>
void _iter_swap(ForwardIterator1 a, ForwardIterator2 b)
{
    auto tmp = *a;
    *a = *b;
    *b = tmp;
}

template <typename ForwardIterator1, typename ForwardIterator2>
void iter_swap(ForwardIterator1 a, ForwardIterator2 b)
{
    _iter_swap(a, b);
}

#endif
