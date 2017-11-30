#ifndef __search_h
#define __search_h

template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, 
        ForwardIterator2 first2, ForwardIterator2 last2)
{
    auto d1 = std::distance(first1, last1);
    auto d2 = std::distance(first2, last2);

    if (d1 < d2) 
        return last1;

    auto current1 = first1;
    auto current2 = first2;

    while (current2 != last2) {
        if (*current1 == *current2) {
            ++current1;
            ++current2;
        } else {
            if (d1 == d2) {
                return last1;
            } else {
                current1 = ++first1;
                current2 = first2;
                --d1;
            }
        }
    }
    return first1;
}

template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1 search(ForwardIterator1 first1, ForwardIterator1 last1, 
        ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred)
{
    auto d1 = std::distance(first1, last1);
    auto d2 = std::distance(first2, last2);

    if (d1 < d2) 
        return last1;

    auto current1 = first1;
    auto current2 = first2;

    while (current2 != last2) {
        if (pred(*current1, *current2)) {
            ++current1;
            ++current2;
        } else {
            if (d1 == d2) {
                return last1;
            } else {
                current1 = ++first1;
                current2 = first2;
                --d1;
            }
        }
    }
    return first1;
}

#endif
