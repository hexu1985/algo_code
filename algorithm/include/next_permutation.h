#ifndef __next_permutation_h
#define __next_permutation_h

#include "reverse.h"

template <typename BidirectionalIterator>
bool next_permutation(BidirectionalIterator first, BidirectionalIterator last)
{
    if (first == last)
        return false;

    auto i = first;
    ++i;
    if (i == last)
        return false;

    i = last;
    --i;

    while (true) {
        auto ii = i;
        --i;
        if (*i < *ii) {
            auto j = last;
            do {
                --j;
            } while (!(*i < *j));
            std::iter_swap(i, j);
            reverse(ii, last);
            return true;
        }
        if (i == first) {
            reverse(first, last);
            return false;
        }
    }
}

template <typename BidirectionalIterator, typename Compare>
bool next_permutation(BidirectionalIterator first, BidirectionalIterator last, Compare comp)
{
    if (first == last)
        return false;

    auto i = first;
    ++i;
    if (i == last)
        return false;

    i = last;
    --i;

    while (true) {
        auto ii = i;
        --i;
        if (comp(*i, *ii)) {
            auto j = last;
            do {
                --j;
            } while (!comp(*i, *j));
            std::iter_swap(i, j);
            reverse(ii, last);
            return true;
        }
        if (i == first) {
            reverse(first, last);
            return false;
        }
    }
}

#endif
