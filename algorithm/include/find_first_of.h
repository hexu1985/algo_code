#ifndef __find_first_of_h
#define __find_first_of_h

template <typename InputIterator, typename ForwardIterator>
InputIterator find_first_of(InputIterator first1, InputIterator last1,
        ForwardIterator first2, ForwardIterator last2)
{
    for ( ; first1 != last1; ++first1) {
        for (auto iter = first2; iter != last2; ++iter) {
            if (*first1 == *iter)
                return first1;
        }
    }
    return last1;
}

template <typename InputIterator, typename ForwardIterator, typename BinaryPredicate>
InputIterator find_first_of(InputIterator first1, InputIterator last1, 
        ForwardIterator first2, ForwardIterator last2, BinaryPredicate pred)
{
    for ( ; first1 != last1; ++first1) {
        for (auto iter = first2; iter != last2; ++iter) {
            if (pred(*first1, *iter))
                return first1;
        }
    }
    return last1;
}

#endif
