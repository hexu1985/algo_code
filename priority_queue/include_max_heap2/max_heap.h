#ifndef __max_heap_h
#define __max_heap_h

#include <assert.h>
#include <utility>

/** 
 * 数组实现的最大二叉堆:
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
 *  array[i]的父节点: array[(i-1)/2]
 *  array[i]的左子节点: array[i*2+1]
 *  array[i]的右子节点: array[i*2+2]
 */

template <typename T>
struct Max_heap {
	int heap_size = 0;	// 堆中元素个数
	T *array = 0;	    // 堆实际空间

    // 返回当前索引的父结点索引
    static int parent(int i) { return (i-1)/2; }

    // 返回当前索引的左子结点索引
    static int left(int i) { return i*2+1; }

    // 返回当前索引的右子结点索引
    static int right(int i) { return i*2+2; }

    // 维护最大堆性质
    void heapify(int i)
    {
        using std::swap;
        int l = left(i);
        int r = right(i);
        int largest = i;
        if (l < heap_size && array[i] < array[l]) {
            largest = l;
        }
        if (r < heap_size && array[i] < array[r]) {
            largest = r;
        }
        if (largest != i) {
            swap(array[i], array[largest]);
            heapify(largest);
        }
    }

    // 创建最大堆
    void build_heap()
    {
        for (int i = parent(heap_size-1); i >= 0; --i) {
            heapify(i);
        }
    }

    // 返回第一破坏堆属性的元素的索引值, 如果没有返回heap_size
    int is_heap_until() const
    {
        for (int i = 0; i <= parent(heap_size-1); ++i) {
            int l = left(i);
            if (l < heap_size && array[i] < array[l])
                return i;
            int r = right(i);
            if (r < heap_size && array[i] < array[r])
                return i;
        }
        return heap_size;
    }

    // 判断是否为最大堆
    bool is_heap() const { return is_heap_until() == heap_size; }

    // 返回堆中最大元素
    const T &top() const { return array[0]; }

    // 堆是否为空
    bool empty() const { return heap_size == 0; }

    // 返回堆中元素个数
    int size() const { return heap_size; }
    
    // 返回堆中数据实际存储空间
    T *data() { return array; }

    // 返回并删除堆中最大元素
    T pop()
    {
        assert(!empty() && "heap underflow");
        T tmp = array[0];
        array[0] = array[heap_size-1];
        heap_size -= 1;
        heapify(0);
        return tmp;
    }

    // 向上维护堆性质
    void fixup_heap(int i)
    {
        using std::swap;
        while (i > 0 && array[parent(i)] < array[i]) {
            swap(array[i], array[parent(i)]);
            i = parent(i);
        }
    }

    // 向堆中插入一个元素
    void push(const T &val)
    {
        heap_size += 1;
        array[heap_size-1] = val;
        fixup_heap(heap_size-1);
    }

    // 交换两个堆
    void swap(Max_heap &x)
    {
        Max_heap tmp = *this;
        *this = x;
        x = tmp;
    }
};

#endif
