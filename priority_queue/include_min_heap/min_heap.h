#ifndef __min_heap_h
#define __min_heap_h

#include <assert.h>
#include <utility>

/** 
 * 数组实现的最小二叉堆
 *
 *                 1(1)
 *               /   \
 *             /       \
 *           /           \
 *          2(2)          3(3)
 *        /  \           /  \
 *      /      \       /      \
 *     16(4)    14(5) 9(6)    10(7)
 *   /   \     /  \
 *  8(8) 4(9) 7(10) 
 *
 *  | 1| 2| 3| 4| 5| 6| 7| 8| 9|10|
 *  | 1| 2| 3|16|14| 9|10| 8| 4| 7|
 */
template <typename T>
struct Min_heap {
	int size;	// 堆中元素个数
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

// 维护最小堆性质
template <typename T, typename Compare = std::less<T>>
void heap_heapify(Min_heap<T> &heap, int i, const Compare &comp = Compare())
{
    using std::swap;
    auto l = heap_left(i);
    auto r = heap_right(i);
    auto least = i;
    if (l <= heap.size && comp(heap.array[l], heap.array[least])) {
        least = l;
    }
    if (r <= heap.size && comp(heap.array[r], heap.array[least])) {
        least = r;
    }
    if (least != i) {
        swap(heap.array[i], heap.array[least]);
        heap_heapify(heap, least, comp);
    }
}

// 创建最小堆
template <typename T, typename Compare = std::less<T>>
void heap_init(Min_heap<T> &heap, T *array, int n = 0, const Compare &comp = Compare())
{
    heap.array = array;
    heap.size = n;
    for (int i = heap.size/2; i >= 1; --i) {
        heap_heapify(heap, i, comp);
    }
}

// 判断是否为堆
template <typename T, typename Compare = std::less<T>>
bool is_heap(T *array, int n, const Compare &comp = Compare())
{
    for (int i = n/2; i >= 1; --i) {
        auto l = heap_left(i);
        if (l <= n && comp(array[l], array[i])) { // l < i
            return false;
        }
        auto r = heap_right(i);
        if (r <= n && comp(array[r], array[i])) { // r < i
            return false;
        }
    }
    return true;
}

// 将一个已堆化的内存赋值给当前堆
template <typename T, typename Compare = std::less<T>>
void heap_assign(Min_heap<T> &heap, T *array, int n, const Compare &comp = Compare())
{
    assert(is_heap(array, n, comp));

    heap.array = array;
    heap.size = n;
}

// 返回堆中最小元素
template <typename T>
const T &heap_top(const Min_heap<T> &heap)
{
    return heap.array[1];
}

// 堆是否为空
template <typename T>
bool heap_is_empty(const Min_heap<T> &heap)
{
    return heap.size == 0;
}

// 返回堆中元素个数
template <typename T>
int heap_size(const Min_heap<T> &heap)
{
    return heap.size;
}

// 返回堆中数据实际存储空间
template <typename T>
T *heap_data(Min_heap<T> &heap)
{
    return heap.array;
}

// 返回并删除堆中最小元素
template <typename T, typename Compare = std::less<T>>
T heap_extract(Min_heap<T> &heap, const Compare &comp = Compare())
{
    assert(!heap_is_empty(heap) && "heap underflow");
    auto min = heap.array[1];
    heap.array[1] = heap.array[heap.size];
    heap.size -= 1;
    heap_heapify(heap, 1, comp);
    return min;
}

template <typename T, typename Compare = std::less<T>>
void heap_decrease_key(Min_heap<T> &heap, int i, const T &key, const Compare &comp = Compare())
{
    using std::swap;

    assert(!comp(heap.array[i], key) && "new key is smaller than current key"); // key <= array[i] <=> !(array[i] < key)

    heap.array[i] = key;
    while (i > 1 && comp(heap.array[i], heap.array[heap_parent(i)])) {
        swap(heap.array[i], heap.array[heap_parent(i)]);
        i = heap_parent(i);
    }
}

// 向堆中插入一个元素
template <typename T, typename Compare = std::less<T>>
void heap_insert(Min_heap<T> &heap, const T &key, const Compare &comp = Compare())
{
    using std::swap;

    heap.size += 1;
    heap.array[heap.size] = key;

    heap_decrease_key(heap, heap.size, key, comp);
}

#endif
