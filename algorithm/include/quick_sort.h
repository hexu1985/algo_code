#ifndef __quick_sort_h
#define __quick_sort_h

template <typename RandomAccessIterator>
RandomAccessIterator _partition(RandomAccessIterator first, RandomAccessIterator last)
{
    auto pivot = first;
    while (true) {
        do {
            ++first;
        } while (first < last && *first < *pivot);

        do {
            --last;
        } while (*pivot < *last);

        if (first < last)
            std::iter_swap(first, last);
        else {
            std::iter_swap(pivot, last);
            return last;
        }
    }
}

template <typename RandomAccessIterator>
void quick_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (first < last - 1) {
        auto iter = _partition(first, last);
        quick_sort(first, iter);
        quick_sort(iter+1, last);
    }
}

template <typename RandomAccessIterator, typename Compare>
RandomAccessIterator _partition(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    auto pivot = first;
    while (true) {
        do {
            ++first;
        } while (first < last && comp(*first, *pivot));

        do {
            --last;
        } while (comp(*pivot, *last));

        if (first < last)
            std::iter_swap(first, last);
        else {
            std::iter_swap(pivot, last);
            return last;
        }
    }
}

template <typename RandomAccessIterator, typename Compare>
void quick_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    if (first < last - 1) {
        auto iter = _partition(first, last, comp);
        quick_sort(first, iter, comp);
        quick_sort(iter+1, last, comp);
    }
}

#endif
