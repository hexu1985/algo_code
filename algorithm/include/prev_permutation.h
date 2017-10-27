#ifndef __prev_permutation_h
#define __prev_permutation_h

#include "reverse.h"

template <typename BidirectionalIterator>
bool prev_permutation(BidirectionalIterator first, BidirectionalIterator last)
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
        if (*ii < *i) {
            auto j = last;
            do {
                --j;
            } while (!(*j < *i));
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
bool prev_permutation(BidirectionalIterator first, BidirectionalIterator last, Compare comp)
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
        if (comp(*ii, *i)) {
            auto j = last;
            do {
                --j;
            } while (!comp(*j, *i));
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
