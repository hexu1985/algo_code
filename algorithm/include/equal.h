#ifndef __equal_h
#define __equal_h

template <typename InputIterator1, typename InputIterator2>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
    for (; first1 != last1; ++first1, ++first2) {
        if (*first1 != *first2)
            return false;
    }

    return true;
}

template <typename InputIterator1, typename T>
bool equal(InputIterator1 first1, InputIterator1 last1, T *first2)
{
    for (; first1 != last1; ++first1, ++first2) {
        if (*first1 != *first2)
            return false;
    }

    return true;
}

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred)
{
    for (; first1 != last1; ++first1, ++first2) {
        if (!pred(*first1, *first2))
            return false;
    }

    return true;
}

template <typename InputIterator1, typename T, typename BinaryPredicate>
bool equal(InputIterator1 first1, InputIterator1 last1, T *first2, BinaryPredicate pred)
{
    for (; first1 != last1; ++first1, ++first2) {
        if (!pred(*first1, *first2))
            return false;
    }

    return true;
}

#endif
