#ifndef __dclist_util_h
#define __dclist_util_h

#include <iostream>
#include "dclist.h"

template<typename T>
std::ostream& operator<<(std::ostream& s, const DCList<T>& v) {
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    auto print_data = [&](const T &e) {
        s << comma << e;
        comma[0] = ',';
    };

    list_for_each(const_cast<DCList<T> *>(&v), print_data);
    return s << ']';
}

template <typename T>
void list_init(DCList<T> *list)
{
    list_init(static_cast<DCList_base *>(list));
}

template <typename T>
void list_init(DCList<T> *list, std::initializer_list<T> il)
{
    list_init(static_cast<DCList_base *>(list));
    for (auto &e : il) {
        list_insert_tail(list, new DCList_node<T>(e));
    }
}

template <typename T>
void list_init(DCList<T> *list, size_t n, const T &val = T())
{
    list_init(static_cast<DCList_base *>(list));
    for (size_t i = 0; i < n; i++) {
        list_insert_tail(list, new DCList_node<T>(val));
    }
}

template <typename T, typename InputIterator, 
    typename = typename std::enable_if<!std::is_integral<InputIterator>::value>::type>
void list_init(DCList<T> *list, InputIterator first, InputIterator last)
{
    list_init(static_cast<DCList_base *>(list));
    while (first != last) {
        list_insert_tail(list, new DCList_node<T>(*first++));
    }
}

#endif
