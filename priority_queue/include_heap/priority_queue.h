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
    priority_queue(int n = DEFAULT_SIZE)
    {
        capacity = n;
        heap_init(self, new T[capacity], 0, comp);
    }

    // 复制priority_queue
    priority_queue(const priority_queue &x)
    {
        auto n = x.size()+1;
        auto length = n * EXTAND_FACTOR;
        T *array = new T[length];
        for (int i = 1; i < n; i++) {
            array[i] = x.data()[i];
        }
        heap_init(self, array, n);
    }

    // 销毁priority_queue对象
    ~priority_queue()
    {
        delete [] data();
    }
}


#endif
