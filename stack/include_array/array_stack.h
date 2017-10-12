#ifndef	__array_stack_h
#define	__array_stack_h

#include <assert.h>

// 数组实现的栈
// index: [1][2][3]...[n]
// array: [x][x][x]...[x]
//               ^top
template <typename T>
struct Stack {
	int top;	// 栈顶下标
	T  *array;	// 栈实际空间
};

// 初始化栈, n为栈内元素个数
template <typename T>
void stack_init(Stack<T> &stack, T *array, int n = 0)
{
    stack.top = n;
    stack.array = array;
}

// 获取存放数据的数组
template <typename T>
T *stack_data(Stack<T> &stack)
{
    return stack.array;
}

// 返回当前栈中元素个数
template <typename T>
int stack_size(const Stack<T> &stack)
{
    return stack.top;
}

// 判断栈是否为空
template <typename T>
bool stack_is_empty(const Stack<T> &stack)
{
    return stack.top == 0;
}

// 入栈
template <typename T>
void stack_push(Stack<T> &stack, const T &x)
{
	stack.top += 1;
	stack.array[stack.top] = x;
}

// 查看栈顶元素
template <typename T>
T &stack_peek(Stack<T> &stack)
{
    assert(!stack_is_empty(stack) && "stack empty");
    return stack.array[stack.top];
}

// 出栈
template <typename T>
T stack_pop(Stack<T> &stack)
{
    assert(!stack_is_empty(stack) && "underflow");
	stack.top -= 1;
	return stack.array[stack.top+1];
}

template <typename T>
void stack_swap(Stack<T> &stack1, Stack<T> &stack2)
{
    Stack<T> tmp = stack1;
    stack1 = stack2;
    stack2 = tmp;
}

#endif	// __stack_h
