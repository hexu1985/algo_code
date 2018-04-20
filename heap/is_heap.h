#ifndef __IS_HEAP_H
#define __IS_HEAP_H

// 判断vector是否为heap
template <typename T, typename Compare>
bool isHeap(vector<T>& v, Compare comp);

// 实现
template <typename T, typename Compare>
bool isHeap(vector<T>& v, Compare comp)
{
    return isHeapUntil(v, comp) == v.size();
}

#endif
