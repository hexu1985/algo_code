#ifndef __heap_common_h
#define __heap_common_h

/** 
 * 最大二叉堆:
 *
 *                16(0)
 *               /   \
 *             /       \
 *           /           \
 *         14(1)          10(2)
 *        /  \           /  \
 *      /      \       /      \
 *     8(3)     7(4)  9(5)    3(6)
 *   /   \     /  \
 *  2(7) 4(8) 1(9) 
 *
 *  | 0| 1| 2| 3| 4| 5| 6| 7| 8| 9|
 *  |16|14|10| 8| 7| 9| 3| 2| 4| 1|
 *
 *  数组下标从0开始
 *  array[n]的父节点: array[(n-1)/2]
 *  array[n]的左子节点: array[n*2+1]
 *  array[n]的右子节点: array[n*2+2]
 */

template <typename Distance>
Distance _heap_parent(Distance n)
{
    return (n-1)/2;
}

template <typename Distance>
Distance _heap_left(Distance n)
{
    return n*2+1;
}

template <typename Distance>
Distance _heap_right(Distance n)
{
    return n*2+2;
}

template <typename RandomAccessIterator, typename Distance>
void _heap_heapify(RandomAccessIterator first, Distance i, Distance heap_size)
{
    auto l = _heap_left(i);
    auto r = _heap_right(i);
    auto largest = i;
    if (l < heap_size && first[largest] < first[l]) {
        largest = l;
    }
    if (r < heap_size && first[largest] < first[r]) {
        largest = r;
    }
    if (largest != i) {
        std::iter_swap(first+i, first+largest);
        _heap_heapify(first, largest, heap_size);
    }
}

template <typename RandomAccessIterator, typename Distance, typename Compare>
void _heap_heapify(RandomAccessIterator first, Distance i, Distance heap_size, Compare comp)
{
    auto l = _heap_left(i);
    auto r = _heap_right(i);
    auto largest = i;
    if (l < heap_size && comp(first[largest], first[l])) {
        largest = l;
    }
    if (r < heap_size && comp(first[largest], first[r])) {
        largest = r;
    }
    if (largest != i) {
        std::iter_swap(first+i, first+largest);
        _heap_heapify(first, largest, heap_size, comp);
    }
}

#endif
