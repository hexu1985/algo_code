#ifndef __priority_queue_h
#define __priority_queue_h

template <typename T, typename C = void, typename Compare = std::less<T>>    // typename C 是为了适配std::priority_queue接口
class priority_queue {
private:
    Heap<T> self;
    int capacity;
    Compare comp;

protected:
    enum { DEFAULT_SIZE = 64, EXTAND_FACTOR = 2 };

    T *data()
    {
        return heap_data(self);
    }

    bool full()
    {
        return heap_size(self)+1 == capacity;
    }

    void extend()
    {
        capacity *= EXTAND_FACTOR;
        T *array = new T[capacity];

        // 将内容复制到新的数组
        auto n = heap_size(self);
        for (int i = 1; i <= n; i++) {
            array[i] = heap_data(self)[i];
        }
        delete [] data();

        heap_init(self, array, n, comp);
    }

public:
    typedef T value_type;
    typedef size_t size_type;
    typedef C container_type;
    typedef T &reference;
    typedef const T &const_reference;

    // 适配std::priority_queue的从容器构造函数
	template <typename Container>
    explicit priority_queue(const Container &cont)
    {
        // 分配空间
        capacity = (cont.size()+1) * EXTAND_FACTOR;
        T *array = new T[capacity];

        // 复制元素
        int i = 1;
        for (auto &item :cont) {
            array[i++] = item;
        }

        // 初始化堆
        heap_init(self, array, cont.size(), comp);
    }

    // 构造一个空的priority_queue对象
    priority_queue()
    {
        capacity = DEFAULT_SIZE;
        heap_init(self, new T[DEFAULT_SIZE], 0, comp);
    }

    // 复制priority_queue
    priority_queue(const priority_queue &x)
    {
        capacity = (x.size()+1) * EXTAND_FACTOR;
        T *array = new T[array];

        for (int i = 1; i <= x.size(); i++) {
            array[i] = x.data()[i];
        }
        heap_init(self, array, x.size());
    }

    // 销毁priority_queue对象
    ~priority_queue()
    {
        delete [] data();
    }

    // 返回heap中元素个数
    size_type size() const 
    {
        return heap_size(self);
    }

    // 返回heap是否为空
    bool empty() const 
    {
        return heap_is_empty(self);
    }

    // 往heap中push一个元素
    void push(const T& elem) 
    {
        if (full()) {
            extend();
        }

        heap_push(self, elem);
    }

    // 从heap中pop一个元素
    void pop() 
    {
        assert(!empty());

        heap_pop(self);
    }

    // 返回heap顶部元素的引用
    T& top() 
    {
        assert(!empty());

        return heap_peek(self);
    }

    // 交换两个heap的所有元素
    void swap(heap &x)
    {
        using std::swap;
        heap_swap(self, x.self);
        swap(capacity, x.capacity);
    }
}


#endif
