#ifndef __queue_h
#define __queue_h

#include "array_queue.h"
#include <stddef.h>
#include <assert.h>

// 队列结构: FIFO, 先进先出
template <typename T, typename C = void>    // typename C 是为了适配std::queue接口
class queue {
private:
    Queue<T> self;
    int capacity;

protected:
    enum { DEFAULT_SIZE = 64, EXTAND_FACTOR = 2 };

    T *data()
    {
        return queue_data(self);
    }

    bool full()
    {
        return queue_is_full(self);
    }

    void extend()
    {
        capacity *= EXTAND_FACTOR;
        Queue<T> tmp;
        queue_init(tmp, new T[capacity], capacity-1);

        // 将内容复制到新的数组
        queue_linear_copy(tmp, self);
        delete [] data();

        self = tmp;
    }

public:
    typedef T value_type;
    typedef size_t size_type;
    typedef C container_type;
    typedef T &reference;
    typedef const T &const_reference;

    // 适配std::queue的从容器构造函数
	template <typename Container>
    explicit queue(const Container &cont)
    {
        // 分配空间
        capacity = (cont.size()+1) * EXTAND_FACTOR;
        T *array = new T[capacity];

        // 复制元素
        int i = 1;
        for (auto &item :cont) {
            array[i++] = item;
        }

        // 初始化栈
        queue_init(self, array, capacity-1, cont.size());
    }

    // 构造一个空的queue对象
    queue()
    {
        capacity = DEFAULT_SIZE;
        queue_init(self, new T[capacity], capacity-1);
    }

    // 复制queue
    queue(const queue &x)
    {
        capacity = (x.size()+1) * EXTAND_FACTOR;
        queue_init(self, new T[capacity], capacity-1);

        // 将内容复制到新的数组
        queue_linear_copy(self, x.self);
    }

    // 销毁queue对象
    ~queue()
    {
        delete [] data();
    }

    // 返回queue中元素个数
    size_type size() const 
    {
        return queue_size(self);
    }

    // 返回queue是否为空
    bool empty() const 
    {
        return queue_is_empty(self);
    }

    // 往queue中push一个元素
    void push(const T& elem) 
    {
        if (full()) {
            extend();
        }

        queue_enqueue(self, elem);
    }

    // 从queue中pop一个元素
    void pop() 
    {
        assert(!empty());

        queue_dequeue(self);
    }

    // 返回queue头部元素的引用
    T& front() 
    {
        assert(!empty());

        return queue_head(self);
    }

    // 返回queue尾部元素的引用
    T& back() 
    {
        assert(!empty());

        return queue_tail(self);
    }

    // 交换两个queue的所有元素
    void swap(queue &x)
    {
        using std::swap;
        swap(self, x.self);
        swap(capacity, x.capacity);
    }
};

#endif
