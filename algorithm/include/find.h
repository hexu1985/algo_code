#ifndef __find_h
#define __find_h

template <typename InputIterator, typename T>
InputIterator find(InputIterator first, InputIterator last, const T &value)
{
    while (first != last && *first != value) {
        ++first;
    }

    return first;
}

template <typename InputIterator, typename T, typename BinaryPredicate>
InputIterator find(InputIterator first, InputIterator last, const T &value, BinaryPredicate pred)
{
    while (first != last && !pred(*first, value)) {
        ++first;
    }

    return first;
}

#endif
