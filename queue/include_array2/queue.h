#ifndef __queue_h
#define __queue_h

#include "array_queue.h"
#include <stddef.h>
#include <assert.h>

// 栈结构: LIFO, 后进先出
template <typename T, typename C = void>    // typename C 是为了适配std::queue接口
class queue: public Queue<T> {
protected:
    enum { DEFAULT_SIZE = 64, EXTAND_FACTOR = 2 };

    typedef Queue<T> base;

    void extend()
    {
        auto size = this->size();
        auto length = size * EXTAND_FACTOR;
        T *array = new T[length];
        this->copy_to(array, length);
        T *data = this->data();
        this->assign(array, length, size);
        delete [] data;
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
        auto size = cont.size();
        auto length = size * EXTAND_FACTOR;
        T *array = new T[length];
        int i = 0;
        for (auto &item :cont) {
            array[i++] = item;
        }
        this->assign(array, length, size);
    }

    // 构造一个空的queue对象
    queue(): base(new T[DEFAULT_SIZE], DEFAULT_SIZE) {}

    // 复制queue
    queue(const queue &x)
    {
        auto size = x.size();
        auto length = size * EXTAND_FACTOR;
        T *array = new T[length];
        x.copy_to(array, length);
        this->assign(array, length);
    }

    // 销毁queue对象
    ~queue()
    {
        delete [] this->data();
    }

    // 往queue中push一个元素
    void push(const T& elem) 
    {
        if (this->full()) {
            extend();
        }

        base::push(elem);
    }
};

#endif
