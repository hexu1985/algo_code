#ifndef __count_if_h
#define __count_if_h

#include <iterator>

template <typename InputIterator, typename UnaryPredicate>
typename std::iterator_traits<InputIterator>::difference_type count_if(InputIterator first, InputIterator last, 
        UnaryPredicate pred)
{
    typename std::iterator_traits<InputIterator>::difference_type n = 0;
    for ( ; first != last; ++first)
        if (pred(*first))
            ++n;
    return n;
}

#endif
