#ifndef __IS_HEAP_UNTIL_H
#define __IS_HEAP_UNTIL_H

// 返回vector中第一个不满足heap性质的元素下标
template <typename T, typename Compare>
size_t isHeapUntil(vector<T>& v, Compare comp);

// 实现
template <typename T, typename Compare>
size_t isHeapUntil(vector<T>& v, Compare comp)
{
    int currentPos, childPos, lastPos, lastParentPos;

    lastPos = v.size();
    lastParentPos = (lastPos - 2)/2;
    currentPos = 0;

    for ( ; currentPos < lastParentPos; ++currentPos) {
        childPos = 2 * currentPos + 1;  // 左子节点
        if (comp(v[currentPos], v[childPos]))
            return childPos;

        childPos = childPos + 1;    // 右子节点
        if (comp(v[currentPos], v[childPos]))
            return childPos;
    }

    return lastPos;
}

#endif
