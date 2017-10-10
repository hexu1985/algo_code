#ifndef __array_heap_h
#define __array_heap_h

/** 
 * 数组实现的最大二叉堆
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
    return (i-1)/2;
}

// 返回当前索引的左子结点索引
inline
int heap_left(int i)
{
    return 2*i+1;
}

// 返回当前索引的右子结点索引
inline
int heap_right(int i)
{
    return 2*i+2;
}

// 维护最大堆性质
template <typename T, typename Compare = std::less<T>>
void heap_fix_up(Heap<T> &heap, int i, Compare comp = Compare())
{
    using std::swap;
    auto l = heap_left(i);
    auto r = heap_right(i);
    auto largest = i;
    if (l <= heap.size-1 && comp(heap.array[i], heap.array[l])) {
        largest = l;
    }
    if (r <= heap.size-1 && comp(heap.array[i], heap.array[r])) {
        largest = r;
    }
    if (largest != i) {
        swap(heap.array[i], heap.array[largest]);
        heap_fix_up(heap, largest, comp);
    }
}

// 创建最大堆
template <typename T, typename Compare = std::less<T>>
void heap_init(Heap<T> &heap, T *array, int n, Compare comp = Compare())
{
    heap.size = n;
    for (int i = (n-1)/2; i != 0; --i) {
        heap_fix_up(heap, i, comp);
    }
}


#endif
