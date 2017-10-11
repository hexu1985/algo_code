#ifndef __array_heap_h
#define __array_heap_h

#include <assert.h>
#include <utility>

/** 
 * 数组实现的最大二叉堆
 *
 *                16(1)
 *               /   \
 *             /       \
 *           /           \
 *         14(2)          10(3)
 *        /  \           /  \
 *      /      \       /      \
 *     8(4)     7(5)  9(6)    3(7)
 *   /   \     /  \
 *  2(8) 4(9) 1(10) 
 *
 *  | 1| 2| 3| 4| 5| 6| 7| 8| 9|10|
 *  |16|14|10| 8| 7| 9| 3| 2| 4| 1|
 */
template <typename T>
struct Heap {
	int size;	// 堆大小
	T  *array;	// 堆实际空间
};

// 返回当前索引的父结点索引
inline
int heap_parent(int i)
{
    return i/2;
}

// 返回当前索引的左子结点索引
inline
int heap_left(int i)
{
    return 2*i;
}

// 返回当前索引的右子结点索引
inline
int heap_right(int i)
{
    return 2*i+1;
}

// 维护最大堆性质
template <typename T, typename Compare = std::less<T>>
void heap_heapify(Heap<T> &heap, int i, Compare comp = Compare())
{
    using std::swap;
    auto l = heap_left(i);
    auto r = heap_right(i);
    auto largest = i;
    if (l <= heap.size && comp(heap.array[i], heap.array[l])) {
        largest = l;
    }
    if (r <= heap.size && comp(heap.array[i], heap.array[r])) {
        largest = r;
    }
    if (largest != i) {
        swap(heap.array[i], heap.array[largest]);
        heap_heapify(heap, largest, comp);
    }
}

// 创建最大堆
template <typename T, typename Compare = std::less<T>>
void heap_init(Heap<T> &heap, T *array, int n, Compare comp = Compare())
{
    heap.size = n-1;
    for (int i = heap.size/2; i > 0; --i) {
        heap_heapify(heap, i, comp);
    }
}

// 返回堆中最大元素
template <typename T>
T heap_top(const Heap<T> &heap)
{
    return heap.array[1];
}

// 堆是否为空
template <typename T>
bool heap_is_empty(const Heap<T> &heap)
{
    return heap.size < 1;
}

// 返回堆中元素个数
template <typename T>
int heap_size(const Heap<T> &heap)
{
    return heap.size;
}

// 返回堆中数据实际存储空间
template <typename T>
T *heap_data(Heap<T> &heap)
{
    return heap.array;
}

// 返回并删除堆中最大元素
template <typename T, typename Compare = std::less<T>>
T heap_extract(Heap<T> &heap, Compare comp = Compare())
{
    assert(!heap_is_empty(heap) && "heap underflow");
    auto max = heap.array[1];
    heap.array[1] = heap.array[heap.size];
    heap.size -= 1;
    heap_heapify(heap, 1, comp);
    return max;
}

// 向堆中插入一个元素
template <typename T, typename Compare = std::less<T>>
void heap_insert(Heap<T> &heap, const T &key, Compare comp = Compare())
{
    using std::swap;

    heap.size += 1;
    heap.array[heap.size] = key;

    auto i = heap.size;
    for (int i = heap.size; i > 1 && comp(heap.array[heap_parent(i)], heap.array[i]); ) {
        swap(heap.array[i], heap.array[heap_parent(i)]);
        i = heap_parent(i);
    }
}

#endif
