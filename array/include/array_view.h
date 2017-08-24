#ifndef __array_view_h
#define __array_view_h

// 数组视图
template <typename T>
class Array_view {
private:
    int array_size = 0; // 数组大小
    T *array_data = 0;  // 数组实际空间

public:
    // 默认构造
    Array_view()
    {
    }

    // 初始化栈
    Array_view(T *data, int size)
    {
        assign(data, size);
    }

    // 赋值
    void assign(T *data, int size)
    {
        array_size = size;
        array_data = data;
    }

    // 获取数组的实际地址
    T *data() const
    {
        return array_data;
    }

    // 返回存放数组元素个数
    int size() const
    {
        return array_size;
    }

    // 获取下标为n的元素的引用
    T &operator [](int n) const
    {
        return array_data[n];
    }

    // 获取第一个元素的引用
    T &front() const
    {
        return array_data[0];
    }

    // 获取最后一个元素的引用
    T &back() const
    {
        return array_data[size()-1];
    }

    // 获取第一个元素的指针
    T *begin() const
    {
        return array_data;
    }

    // 获取逾尾元素的指针
    T *end() const
    {
        return array_data+size();
    }

    // 将整个数组的元素填成指定值
    void fill(const T &val)
    {
        for (int i = 0; i < size(); i++) {
            array_data[i] = val;
        }
    }
};

#endif
