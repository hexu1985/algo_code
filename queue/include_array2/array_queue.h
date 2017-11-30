#ifndef	__array_queue_h
#define	__array_queue_h

#include <assert.h>

// 数组实现的队列
// index: [1][2][3]...[7][8][9]...[n]
// array: [x][x][x]...[7][8][9]...[x]
//               ^tail       ^head   
template <typename T>
struct Queue {
	int queue_head = 0;	    // 队列首下标索引
	int queue_tail = 0;	    // 队列尾下标索引
	int queue_length = 0;	// 队列长度
	T *array = 0;	        // 队列实际空间

public:
    // 默认构造
    Queue()
    {
    }

    // 初始化队列
    Queue(T *data, int length, int num_elem = 0)
    {
        assign(data, length, num_elem);
    }

    // 赋值
    void assign(T *data, int length, int num_elem = 0)
    {
        assert(length > 0 && num_elem <= length);
        queue_head = 0;
        queue_tail = num_elem;
        queue_length = length;
        array = data;
    }

    // 复制队列内容到data中
    void copy_to(T *data, int length)
    {
        assert(queue_length <= length);

        int j = 0;
        if (queue_head <= queue_tail) {
            for (int i = queue_head; i < queue_tail; ++i) {
                data[j++] = array[i];
            }
        } else {
            for (int i = queue_head; i < queue_length; ++i) {
                data[j++] = array[i];
            }
            for (int i = 0; i < queue_tail; ++i) {
                data[j++] = array[i];
            }
        }
    }

    // 清空队列
    void clear()
    {
        queue_head = queue_tail = 0;
    }
	
    // 获取存放数据的数组
    T *data() const
    {
        return array;
    }

	// 返回当前队列中元素个数
	size_t size() const
	{
		if (queue_head <= queue_tail)
			return queue_tail-queue_head;
		else 
			return queue_length+queue_tail-queue_head;
	}

	// 返回队列中最大存放元素个数
	size_t capacity() const
	{
		return queue_length-1;
	}

	// 判断队列是否为空
	bool empty() const
	{
		return queue_head == queue_tail;
	}

	// 判断队列是否已满
	bool full() const
	{
		return (queue_tail+1)%queue_length == queue_head;
	}

	// 入队列
	void push(const T &x)
	{
        assert(!full() && "overflow!");
		array[queue_tail] = x;
		queue_tail = (queue_tail+1)%queue_length;
	}

	// 查看队首元素
	T &front() const
	{
        assert(!empty() && "queue is empty!");
		return array[queue_head];
	}

	// 查看队尾元素
    T &back() const
    {
        assert(!empty() && "queue is empty!");
        return array[(queue_tail+queue_length-1)%queue_length];
    }

	// 出队
	T pop()
	{
        assert(!empty() && "underflow!");
		T x = array[queue_head];
		queue_head = (queue_head+1)%queue_length;
		return x;
	}

    // 交换
    void swap(Queue &x)
    {
        Queue tmp = *this;
        *this = x;
        x = tmp;
    }
};

#endif
