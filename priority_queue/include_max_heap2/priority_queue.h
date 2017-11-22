#ifndef __priority_queue_h
#define __priority_queue_h

#include "max_heap.h"
#include <algorithm>

template <typename T, typename C = void, typename Compare = std::less<T>>    // typename C 是为了适配std::priority_queue接口
class priority_queue: public Max_heap<T> {
private:
    int capacity;
    Compare comp;

    typedef Max_heap<T> base;

protected:
    enum { DEFAULT_SIZE = 64, EXTAND_FACTOR = 2 };

    bool full()
    {
        return base::size() == capacity;
    }

    void extend()
    {
        capacity *= EXTAND_FACTOR;
        T *data = new T[capacity];

        // 将内容复制到新的数组
        auto n = base::size();
        for (int i = 1; i <= n; i++) {
            data[i] = base::data()[i];
        }
        delete [] base::data();
        
        base::array = data;
    }

public:
    typedef T value_type;
    typedef size_t size_type;
    typedef C container_type;
    typedef T &reference;
    typedef const T &const_reference;

    // 适配std::priority_queue的从容器构造函数
	template <typename Container>
    explicit priority_queue(const Compare &comp, const Container &cont)
        : comp(comp)
    {
        // 分配空间
        capacity = (cont.size()+1) * EXTAND_FACTOR;
        base::array = new T[capacity];  // base::array
        base::heap_size = cont.size();  // base::heap_size

        // 复制元素
        int i = 1;
        for (auto &item :cont) {
            base::array[i++] = item;
        }

        // 初始化堆
        base::build_heap();
    }

    // 构造一个空的priority_queue对象
    priority_queue(const Compare &comp = Compare())
        : comp(comp)
    {
        capacity = DEFAULT_SIZE;
        base::array = new T[DEFAULT_SIZE];
        base::heap_size = 0;
    }

    // 适配std::priority_queue的从容器构造函数
	template <typename InputIterator>
    explicit priority_queue(InputIterator first, InputIterator last,
            const Compare &comp = Compare())
        : comp(comp)
    {
        int n = std::distance(first, last);

        // 分配空间
        capacity = (n+1) * EXTAND_FACTOR;
        base::array = new T[capacity];
        base::heap_size = n;

        // 复制元素
        int i = 1;
        while (first != last) {
            base::array[i++] = *first++;
        }

        // 初始化堆
        base::build_heap();
    }

    // 复制priority_queue
    priority_queue(const priority_queue &x)
    {
        capacity = (x.size()+1) * EXTAND_FACTOR;
        base::array = new T[capacity];
        base::heap_size = x.size();

        for (int i = 1; i <= x.size(); i++) {
            base::array[i] = x.data()[i];
        }
    }

    // 销毁priority_queue对象
    ~priority_queue()
    {
        delete [] base::data();
    }

    // 往heap中push一个元素
    void push(const T& elem) 
    {
        if (full()) {
            extend();
        }

        base::push(elem);
    }

    // 交换两个heap的所有元素
    void swap(priority_queue &x)
    {
        using std::swap;
        base::swap(x);
        swap(comp, x.comp);
        swap(capacity, x.capacity);
    }
};

#endif
