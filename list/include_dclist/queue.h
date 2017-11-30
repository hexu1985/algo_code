#ifndef __queue_h
#define __queue_h

#include "dclist.h"
#include <stddef.h>
#include <assert.h>

// 队列结构: FIFO, 先进先出
template <typename T, typename C = void>    // typename C 是为了适配std::queue接口
class queue: private DCList<T> {
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
        list_init(this);
        for (auto &item : cont) {
            list_insert_tail(this, new DCList_node<T>(item));
        }
    }

    // 构造一个空的queue对象
    queue()
    {
        list_init(this);
    }

    // 复制queue
    queue(const queue &x)
    {
        list_init(this);
        auto fn = [this] (const T &val) { list_insert_tail(this, new DCList_node<T>(val)); };
        list_for_each(const_cast<queue *>(&x), fn);
    }

    // 销毁queue对象
    ~queue()
    {
        list_clear(this);
    }

    // 返回queue中元素个数
    size_type size() const 
    {
        return list_size(const_cast<queue *>(this));
    }

    // 返回queue是否为空
    bool empty() const 
    {
        return list_is_empty(const_cast<queue *>(this));
    }

    // 往queue中push一个元素
    void push(const T& elem) 
    {
        list_insert_tail(this, new DCList_node<T>(elem));
    }

    // 从queue中pop一个元素
    void pop() 
    {
        assert(!empty());

        delete list_node<T>(list_delete_head(this));
    }

    // 返回queue头部元素的引用
    T& front() 
    {
        assert(!empty());

        return *list_data(list_node<T>(list_head(this)));
    }

    // 返回queue尾部元素的引用
    T& back() 
    {
        assert(!empty());

        return *list_data(list_node<T>(list_tail(this)));
    }

    // 交换两个queue的所有元素
    void swap(queue &x)
    {
        list_swap(this, &x);
    }
};

#endif
