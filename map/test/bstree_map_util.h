#ifndef __bstree_map_util_h
#define __bstree_map_util_h

#include <iostream>
#include "bstree_map.h"

template<typename K, typename V>
std::ostream& operator<<(std::ostream& s, const BSTree_map<K,V>& v) {
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    auto print_data = [&](const std::pair<K,V> &e) {
        s << comma << "{" << e.first << ", " << e.second << "}";
        comma[0] = ',';
    };

    list_for_each(const_cast<BSTree_map<K,V> *>(&v), print_data);
    return s << ']';
}

template <typename K, typename V>
void list_init(BSTree_map<K,V> *list)
{
    list_init(static_cast<BSTree_map_base *>(list));
}

template <typename K, typename V>
void list_init(BSTree_map<K,V> *list, std::initializer_list<K,V> il)
{
    list_init(static_cast<BSTree_map_base *>(list));
    for (auto &e : il) {
        list_insert_tail(list, new BSTree_map_node<K,V>(e));
    }
}

template <typename K, typename V>
void list_init(BSTree_map<K,V> *list, size_t n, const K,V &val = K,V())
{
    list_init(static_cast<BSTree_map_base *>(list));
    for (size_t i = 0; i < n; i++) {
        list_insert_tail(list, new BSTree_map_node<K,V>(val));
    }
}

template <typename K, typename V, typename InputIterator, 
    typename = typename std::enable_if<!std::is_integral<InputIterator>::value>::type>
void list_init(BSTree_map<K,V> *list, InputIterator first, InputIterator last)
{
    list_init(static_cast<BSTree_map_base *>(list));
    while (first != last) {
        list_insert_tail(list, new BSTree_map_node<K,V>(*first++));
    }
}

#endif
