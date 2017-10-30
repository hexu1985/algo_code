#ifndef __is_partitioned_h
#define __is_partitioned_h

template <typename InputIterator, typename UnaryPredicate>
bool is_partitioned(InputIterator first, InputIterator last, UnaryPredicate pred)
{
    while (first != last && pred(*first)) {
        ++first;
    }
    while (first != last) {
        if (pred(*first)) return false;
        ++first;
    }
    return true;
}

#endif
