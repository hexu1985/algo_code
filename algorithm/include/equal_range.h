#ifndef __equal_range_h
#define __equal_range_h

#include "lower_bound.h"
#include "upper_bound.h"

template <typename ForwardIterator, typename T>
std::pair<ForwardIterator, ForwardIterator> _equal_range(ForwardIterator first, ForwardIterator last, const T &value, 
        std::forward_iterator_tag)
{
    auto len = std::distance(first, last);

    while (len > 0) {
        auto half = len/2;
        auto middle = first;
        std::advance(middle, half);
        if (*middle < value) {
            first = middle;
            ++first;
            len = len - half - 1;
        } else if (value < *middle) {
            len = half;
        } else {    // *middle == value
            auto left = _lower_bound(first, middle, value, std::forward_iterator_tag());
            std::advance(first, len);
            auto right = _upper_bound(++middle, first, value, std::forward_iterator_tag());
            return std::make_pair(left, right);
        }
    }
    return std::make_pair(first, first);
}

template <typename RandomAccessIterator, typename T>
std::pair<RandomAccessIterator, RandomAccessIterator> _equal_range(RandomAccessIterator first, RandomAccessIterator last, const T &value, 
        std::random_access_iterator_tag)
{
    auto len = last - first;

    while (len > 0) {
        auto half = len/2;
        auto middle = first + half;
        if (*middle < value) {
            first = middle + 1;
            len = len - half - 1;
        } else if (value < *middle) {
            len = half;
        } else {    // *middle == value
            auto left = _lower_bound(first, middle, value, std::random_access_iterator_tag());
            auto right = _upper_bound(middle+1, first+len, value, std::random_access_iterator_tag());
            return std::make_pair(left, right);
        }
    }
    return std::make_pair(first, first);
}

template <typename ForwardIterator, typename T>
std::pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator first, ForwardIterator last, const T &value)
{
    typedef typename std::iterator_traits<ForwardIterator>::iterator_category category;
    return _equal_range(first, last, value, category());
}

template <typename ForwardIterator, typename T, typename Compare>
std::pair<ForwardIterator, ForwardIterator> _equal_range(ForwardIterator first, ForwardIterator last, const T &value, Compare comp,
        std::forward_iterator_tag)
{
    auto len = std::distance(first, last);

    while (len > 0) {
        auto half = len/2;
        auto middle = first;
        std::advance(middle, half);
        if (comp(*middle, value)) {
            first = middle;
            ++first;
            len = len - half - 1;
        } else if (comp(value, *middle)) {
            len = half;
        } else {    // *middle == value
            auto left = _lower_bound(first, middle, value, comp, std::forward_iterator_tag());
            std::advance(first, len);
            auto right = _upper_bound(++middle, first, value, comp, std::forward_iterator_tag());
            return std::make_pair(left, right);
        }
    }
    return std::make_pair(first, first);
}

template <typename RandomAccessIterator, typename T, typename Compare>
std::pair<RandomAccessIterator, RandomAccessIterator> _equal_range(RandomAccessIterator first, RandomAccessIterator last, const T &value, Compare comp,
        std::random_access_iterator_tag)
{
    auto len = last - first;

    while (len > 0) {
        auto half = len/2;
        auto middle = first + half;
        if (comp(*middle, value)) {
            first = middle + 1;
            len = len - half - 1;
        } else if (comp(value, *middle)) {
            len = half;
        } else {    // *middle == value
            auto left = _lower_bound(first, middle, value, comp, std::random_access_iterator_tag());
            auto right = _upper_bound(middle+1, first+len, value, comp, std::random_access_iterator_tag());
            return std::make_pair(left, right);
        }
    }
    return std::make_pair(first, first);
}

template <typename ForwardIterator, typename T, typename Compare>
std::pair<ForwardIterator, ForwardIterator> equal_range(ForwardIterator first, ForwardIterator last, const T &value, Compare comp)
{
    typedef typename std::iterator_traits<ForwardIterator>::iterator_category category;
    return _equal_range(first, last, value, comp, category());
}

#endif
