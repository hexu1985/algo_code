#ifndef __replace_h
#define __replace_h

template <typename ForwardIterator, typename T>
void replace(ForwardIterator first, ForwardIterator last,
        const T &old_value, const T &new_value)
{
    for ( ; first != last; ++first)
        if (*first == old_value) *first = new_value;
}

#endif
