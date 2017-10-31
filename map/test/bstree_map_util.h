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

template <typename K, typename V, typename Compare = std::less<K>>
void tree_init(BSTree_map<K,V> *tree, std::initializer_list<std::pair<K,V>> il, Compare comp = Compare())
{
    tree_init(static_cast<BSTree_base *>(tree));
    for (auto &e : il) {
        tree_insert(tree, new BSTree_map_node<K,V>(e), comp);
    }
}

template <typename K, typename V, typename InputIterator, typename Compare = std::less<K>>
void tree_init(BSTree_map<K,V> *tree, InputIterator first, InputIterator last, Compare comp = Compare())
{
    tree_init(static_cast<BSTree_base *>(tree));
    while (first != last) {
        tree_insert(tree, new BSTree_map_node<K,V>(*first++), comp);
    }
}

template <typename K, typename V, typename Compare = std::less<K>>
void tree_insert_or_assign(BSTree_map<K,V> *tree, const K &k, const V &v, Compare comp = Compare()) 
{
    auto x = tree_iterative_search(tree, k, comp);
    if (x != NULL) {
        *tree_value(x) = v;
    } else {
        tree_insert(tree, new BSTree_map_node<K,V>(k, v), comp);
    }
}

template <typename K, typename V, typename Compare = std::less<K>>
std::pair<BSTree_map_node<K,V> *, bool> tree_insert_unique(BSTree_map<K,V> *tree, const K &k, const V &v, Compare comp = Compare()) 
{
    auto x = tree_iterative_search(tree, k, comp);
    bool ret = false;
    if (x == NULL) {
        ret = true;
        x = new BSTree_map_node<K,V>(k, v);
        tree_insert(tree, x, comp);
    }
    return std::make_pair(x, ret);
}

#endif
