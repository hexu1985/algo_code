#ifndef __insertion_sort_h
#define __insertion_sort_h

template <typename RandomAccessIterator>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (first == last)
        return;

    for (auto j = first + 1; j != last; ++j) {
        auto val = *j;
        auto i = j - 1;
        while (i >= first && val < *i) {
            *(i+1) = *i;
            --i;
        }
        *(i+1) = val;
    }
}

template <typename RandomAccessIterator, typename Compare>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    if (first == last)
        return;

    for (auto j = first + 1; j != last; ++j) {
        auto val = *j;
        auto i = j - 1;
        while (i >= first && comp(val, *i)) {
            *(i+1) = *i;
            --i;
        }
        *(i+1) = val;
    }
}

#endif
