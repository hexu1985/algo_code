#ifndef __none_of_h
#define __none_of_h

template <typename InputIterator, typename UnaryPredicate>
bool none_of(InputIterator first, InputIterator last, UnaryPredicate pred)
{
    while (first != last) {
        if (pred(*first)) return false;
        ++first;
    }
    return true;
}

#endif
