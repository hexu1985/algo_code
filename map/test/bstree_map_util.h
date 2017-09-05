#ifndef __bstree_map_util_h
#define __bstree_map_util_h

#include <iostream>
#include <initializer_list>
#include "bstree_map.h"

template<typename K, typename V>
std::ostream& operator<<(std::ostream& s, const BSTree_map<K,V>& v) {
    s.put('[');
    char comma[3] = {'\0', ' ', '\0'};
    auto print_data = [&](const std::pair<K,V> &e) {
        s << comma << "{" << e.first << ", " << e.second << "}";
        comma[0] = ',';
    };

    tree_for_each(const_cast<BSTree_map<K,V> *>(&v), print_data);
    return s << ']';
}

template <typename K, typename V>
void tree_init(BSTree_map<K,V> *tree)
{
    tree_init(static_cast<BSTree_base *>(tree));
}

template <typename K, typename V>
void tree_init(BSTree_map<K,V> *tree, std::initializer_list<std::pair<K,V>> il)
{
    tree_init(static_cast<BSTree_base *>(tree));
    for (auto &e : il) {
        tree_insert(tree, new BSTree_map_node<K,V>(e));
    }
}

template <typename K, typename V>
void tree_init(BSTree_map<K,V> *tree, size_t n, const std::pair<K,V> &val = std::pair<K,V>())
{
    tree_init(static_cast<BSTree_base *>(tree));
    for (size_t i = 0; i < n; i++) {
        tree_insert(tree, new BSTree_map_node<K,V>(val));
    }
}

template <typename K, typename V, typename InputIterator, 
    typename = typename std::enable_if<!std::is_integral<InputIterator>::value>::type>
void tree_init(BSTree_map<K,V> *tree, InputIterator first, InputIterator last)
{
    tree_init(static_cast<BSTree_base *>(tree));
    while (first != last) {
        tree_insert(tree, new BSTree_map_node<K,V>(*first++));
    }
}

template <typename K, typename V, typename Compare = std::less<K>>
void tree_insert_or_assign(BSTree_map<K,V> *tree, const K &k, const V &v, Compare comp = Compare()) 
{
    auto x = tree_iterative_search(tree, k, comp);
    if (x != NULL) {
        *tree_value(x) = v;
    } else {
        tree_insert(tree, new BSTree_map_node<K,V>(k, v));
    }
}

#endif
