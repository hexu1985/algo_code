#ifndef __replace_if_h
#define __replace_if_h

template <typename ForwardIterator, typename UnaryPredicate, typename T>
void replace_if(ForwardIterator first, ForwardIterator last, 
        UnaryPredicate pred, const T &new_value)
{
    for ( ; first != last; ++first)
        if (pred(*first)) *first = new_value;
}

#endif
