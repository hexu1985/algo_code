#ifndef __is_permutation_h
#define __is_permutation_h

#include "mismatch.h"
#include "find.h"
#include "count.h"

#define mismatch hex::mismatch

template <typename InputIterator1, typename InputIterator2>
bool is_permutation(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
{
    std::tie(first1, first2) = mismatch(first1, last1, first2);
    if (first1 == last1) 
        return true;

    InputIterator2 last2 = first2; 
    std::advance(last2, std::distance(first1,last1));
    for (InputIterator1 it1 = first1; it1 != last1; ++it1) {
        if (find(first1, it1, *it1) == it1) {
            auto n = count(first2, last2, *it1);
            if (n == 0 || count(it1, last1, *it1) != n) 
                return false;
        }
    }
    return true;
}

template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
bool is_permutation(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2,
        BinaryPredicate pred)
{
    std::tie(first1, first2) = mismatch(first1, last1, first2, pred);
    if (first1 == last1) 
        return true;

    InputIterator2 last2 = first2; 
    std::advance(last2, std::distance(first1,last1));
    for (InputIterator1 it1 = first1; it1 != last1; ++it1) {
        if (find(first1, it1, *it1, pred) == it1) {
            auto n = count(first2, last2, *it1, pred);
            if (n == 0 || count(it1, last1, *it1, pred) != n) 
                return false;
        }
    }
    return true;
}

#undef mismatch

#endif
