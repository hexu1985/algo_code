#ifndef __SORT_HEAP_H
#define __SORT_HEAP_H

// 排序vector中的元素, 使用heap排序算法
template <typename T, typename Compare>
void sortHeap(vector<T>& v, Compare comp);

// 实现
template <typename T, typename Compare>
void sortHeap(vector<T>& v, Compare comp)
{
    int last = v.size();
    for ( ; last > 1; --last)
        popHeap(v, last, comp);
}

#endif
