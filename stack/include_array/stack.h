#ifndef __stack_h
#define __stack_h

#include "array_stack.h"
#include <stddef.h>
#include <assert.h>

// 栈结构: LIFO, 后进先出
template <typename T, typename C = void>    // typename C 是为了适配std::stack接口
class stack {
private:
    Stack<T> self;
    int capacity;

protected:
    enum { DEFAULT_SIZE = 64, EXTAND_FACTOR = 2 };

    T *data()
    {
        return stack_data(self);
    }

    bool full()
    {
        return stack_size(self)+1 == capacity;
    }

    void extend()
    {
        capacity *= EXTAND_FACTOR;
        T *array = new T[capacity];

        // 将内容复制到新的数组
        auto n = stack_size(self);
        for (int i = 1; i <= n; i++) {
            array[i] = stack_data(self)[i];
        }
        delete [] data();

        stack_init(self, array, n);
    }

public:
    typedef T value_type;
    typedef size_t size_type;
    typedef C container_type;
    typedef T &reference;
    typedef const T &const_reference;

    // 适配std::stack的从容器构造函数
	template <typename Container>
    explicit stack(const Container &cont)
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
        stack_init(self, array, cont.size());
    }

    // 构造一个空的stack对象
    stack()
    {
        capacity = DEFAULT_SIZE;
        stack_init(self, new T[capacity]);
    }

    // 复制stack
    stack(const stack &x)
    {
        capacity = (x.size()+1) * EXTAND_FACTOR;
        T *array = new T[array];

        for (int i = 1; i <= x.size(); i++) {
            array[i] = x.data()[i];
        }
        stack_init(self, array, x.size());
    }

    // 销毁stack对象
    ~stack()
    {
        delete [] data();
    }

    // 返回stack中元素个数
    size_type size() const 
    {
        return stack_size(self);
    }

    // 返回stack是否为空
    bool empty() const 
    {
        return stack_is_empty(self);
    }

    // 往stack中push一个元素
    void push(const T& elem) 
    {
        if (full()) {
            extend();
        }

        stack_push(self, elem);
    }

    // 从stack中pop一个元素
    void pop() 
    {
        assert(!empty());

        stack_pop(self);
    }

    // 返回stack顶部元素的引用
    T &top() 
    {
        assert(!empty());

        return stack_peek(self);
    }

    // 交换两个stack的所有元素
    void swap(stack &x)
    {
        using std::swap;
        swap(self, x.self);
        swap(capacity, x.capacity);
    }
};

#endif /* __stl_stack_h */
