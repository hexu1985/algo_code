#ifndef __set_difference_h
#define __set_difference_h

template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2,
        OutputIterator result)
{
    while (first1 != last1 && first2 != last2) {
        if (*first1 < *first2) {
            *result = *first1;
            ++first1;
            ++result;
        } else if (*first2 < *first1) {
            ++first2;
        } else {    // *first1 == *first2
            ++first1;
            ++first2;
        }
    }

    return _copy(first1, last1, result);
}

template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename Compare>
OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, 
        OutputIterator result, Compare comp)
{
    while (first1 != last1 && first2 != last2) {
        if (comp(*first1, *first2)) {
            *result = *first1;
            ++first1;
            ++result;
        } else if (comp(*first2, *first1)) {
            ++first2;
        } else {    // *first1 == *first2
            ++first1;
            ++first2;
        }
    }

    return _copy(first1, last1, result);
}

#endif
