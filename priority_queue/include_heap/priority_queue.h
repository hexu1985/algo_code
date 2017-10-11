#ifndef __priority_queue_h
#define __priority_queue_h

template <typename T, typename C = void, typename Compare = std::less<T>>    // typename C 是为了适配std::priority_queue接口
class priority_queue {
private:
    Heap<T> heap;
    int capacity;

protected:
    enum { DEFAULT_SIZE = 64, EXTAND_FACTOR = 2 };

    T *data()
    {
        return heap_data(heap);
    }

    bool full()
    {
        return heap_size(heap)+1 == capacity;
    }

    void extend()
    {
        capacity *= EXTAND_FACTOR;
        auto n = heap_size(heap)+1;
        T *array = new T[capacity];
        for (int i = 1; i < n; i++) {    // copy
            array[i] = heap_data(heap)[i];
        }
        delete [] data();
        heap_init(heap, array, n);
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
        auto n = cont.size()+1;
        capacity = n * EXTAND_FACTOR;
        T *array = new T[capacity];
        int i = 1;
        for (auto &item :cont) {
            array[i++] = item;
        }
        heap_init(heap, array, n);
    }

    // 构造一个空的priority_queue对象
    priority_queue(int n = DEFAULT_SIZE)
    {
        capacity = n;
        heap_init(heap, new T[n], 0);
    }

    // 复制priority_queue
    priority_queue(const priority_queue &x)
    {
        auto n = x.size()+1;
        auto length = n * EXTAND_FACTOR;
        T *array = new T[length];
        for (int i = 1; i < n; i++) {
            array[i+1] = x.data()[i];
        }
        heap_init(heap, array, n);
    }

    // 销毁priority_queue对象
    ~priority_queue()
    {
        delete [] data();
    }
}


#endif
