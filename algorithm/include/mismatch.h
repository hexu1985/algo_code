#ifndef __mismatch_h
#define __mismatch_h

template <typename InputIterator1, typename InputIterator2>
std::pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1, 
        InputIterator2 first2)
{
    while (first1 != last1 && *first1 == *first2) {
        ++first1;
        ++first2;
    }
    return std::make_pair(first1, first2);
}

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
std::pair<InputIterator1, InputIterator2> mismatch(InputIterator1 first1, InputIterator1 last1, 
        InputIterator2 first2, BinaryPredicate pred)
{
    while (first1 != last1 && pred(*first1, *first2)) {
        ++first1;
        ++first2;
    }
    return std::make_pair(first1, first2);
}

#endif
