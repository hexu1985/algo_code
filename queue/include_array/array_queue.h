#ifndef __array_queue_h
#define __array_queue_h

#include <assert.h>

// 数组实现的队列
// index: [1][2][3]...[7][8][9]...[n]
// array: [x][x][x]...[7][8][9]...[x]
//               ^tail       ^head   
template <typename T>
struct Queue {
    int head;
    int tail;
    int length;
    T  *array;
};

// 初始化队列, n为队列内元素个数
template <typename T>
void queue_init(Queue<T> &queue, T *array, int length, int num_elem = 0)
{
    assert(num_elem <= length);
    queue.head = 1;
    queue.tail = queue.head+num_elem;
    queue.length = length;
    queue.array = array;
}

// 获取存放数据的数组
template <typename T>
T *queue_data(Queue<T> &queue)
{
    return queue.array;
}

// 返回当前队列中元素个数
template <typename T>
int queue_size(const Queue<T> &queue)
{
    if (queue.head <= queue.tail)
        return queue.tail - queue.head;
    else
        return queue.length + queue.tail - queue.head;
}

// 判断队列是否为空
template <typename T>
bool queue_is_empty(const Queue<T> &queue)
{
    return queue.head == queue.tail;
}

// 判断队列是否已满
template <typename T>
bool queue_is_full(const Queue<T> &queue)
{
    if (queue.head <= queue.tail)
        return queue.head == 1 && queue.tail == queue.length;
    else
        return queue.tail == queue.head + 1;
}

// 入队列
template <typename T>
void queue_enqueue(Queue<T> &queue, const T &x)
{
    assert(!queue_is_full(queue) && "overflow");
    queue.array[queue.tail] = x;
    if (queue.tail == queue.length)
        queue.tail = 1;
    else
        queue.tail += 1;
}

// 出队列
template <typename T>
T queue_dequeue(Queue<T> &queue)
{
    assert(!queue_is_empty(queue) && "underflow");

    auto x = queue.array[queue.head];
    if (queue.head == queue.length) {
        queue.head = 1;
    } else {
        queue.head += 1;
    }

	return x;
}

// 查看队列头部元素
template <typename T>
T &queue_head(Queue<T> &queue)
{
    assert(!queue_is_empty(queue) && "queue empty");
    return queue.array[queue.head];
}

// 查看队列尾部元素
template <typename T>
T &queue_tail(Queue<T> &queue)
{
    assert(!queue_is_empty(queue) && "queue empty");
    if (queue.tail == 1)
        return queue.array[queue.length];
    else
        return queue.array[queue.tail-1];
}

// 将src中元素复制到dst中, 调用者保证dst可以容纳src中的所有元素
template <typename T>
void queue_linear_copy(Queue<T> &dst, Queue<T> &src)
{
    assert(dst.length >= src.length);
    dst.head = 1;
    dst.tail = 1;
    if (src.head <= src.tail) {
        for (int i = src.head; i < src.tail; ++i) {
            dst.array[dst.tail++] = src.array[i];
        }
    } else {
        for (int i = src.head; i <= src.length; ++i) {
            dst.array[dst.tail++] = src.array[i];
        }
        for (int i = 1; i < src.tail; ++i) {
            dst.array[dst.tail++] = src.array[i];
        }
    }
}

#endif
