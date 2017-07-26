#ifndef __dclist_node_h
#define __dclist_node_h

#include <functional>
#include "dclist_node_base.h"

// double chain list node
template <typename T>
struct DCList_node : public DCList_node_base {
    T data;  // 数据成员

    DCList_node() {} 
    DCList_node(const T &data) { this->data = data; } 
};

// 将DCList_link强转成DCList_node<T> *
template <typename T>
DCList_node<T> *list_node(DCList_link x)
{
    return static_cast<DCList_node<T> *>(x);
}

template <typename T>
DCList_node<T> *list_next(DCList_node<T> *x)
{
    return list_node<T>(x->next);
}

template <typename T>
DCList_node<T> *list_prev(DCList_node<T> *x)
{
    return list_node<T>(x->prev);
}

// 获取element数据成员
template <typename T>
T *list_data(DCList_node<T> *x)
{
    return &(x->data);
}

// 遍历list的[x, y)区间所有结点, Function处理data
template <typename T, typename Function>
void list_for_each(DCList_node<T> *x, DCList_node<T> *y, Function fn)
{
    for ( ; x != y; x = list_next(x)) {
        fn(*list_data(x));
    }
}

// 查找list的[x, y)区间中data等于指定值的结点
template <typename T>
DCList_node<T> *list_search(DCList_node<T> *x, DCList_node<T> *y, const T &val)
{
    while (x != y && *list_data(x) != val) {
        x = list_next(x);
    }
    return x;
}

template <typename T, typename Predicate>
DCList_node<T> *list_search_if(DCList_node<T> *x, DCList_node<T> *y, Predicate pred)
{
    while (x != y && !pred(*list_data(x))) {
        x = list_next(x);
    }
    return x;
}

#endif

