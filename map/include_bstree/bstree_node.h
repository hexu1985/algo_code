#ifndef __bstree_node_h
#define __bstree_node_h

#include "bstree_node_base.h"

// 二叉查找树结点
// key为索引
// value为数据
template <typename K, typename V>
struct BSTree_node : public BSTree_node_base {
    K key;
    V value;

    BSTree_node() { } 

    BSTree_node(const K &k, const V &v) 
    {
        this->key = k; 
        this->value = v;
    } 
};

// 将BSTree_link强转成BSTree_node<K, V> *
template <typename K, typename V>
BSTree_node<K,V> *tree_node(BSTree_link x)
{
    return static_cast<BSTree_node<K,V> *>(x);
}

template <typename K, typename V>
BSTree_node<K,V> *tree_left(BSTree_node<K,V> *x)
{
    return tree_node<K,V>(x->left);
}

template <typename K, typename V>
BSTree_node<K,V> *tree_right(BSTree_node<K,V> *x)
{
    return tree_node<K,V>(x->right);
}

template <typename K, typename V>
BSTree_node<K,V> *tree_parent(BSTree_node<K,V> *x)
{
    return tree_node<K,V>(x->parent);
}

// 获取key数据成员
template <typename K, typename V>
T *tree_key(BSTree_node<K,V> *x)
{
    return &(x->key);
}

// 获取value数据成员
template <typename K, typename V>
T *tree_value(BSTree_node<K,V> *x)
{
    return &(x->value);
}

/**
 * 从二叉搜索树中从x为根结点的子树向下查找等于特定值的结点
 * 如果未找到, 返回NIL
 * 递归实现
 */
template <typename K, typename V>
BSTree_node<K,V> *tree_search(BSTree_node<K,V> *x, const K &k)
{
    while (x == NULL || k == *tree_key(x))
        return x;

    if (k < *tree_key(x))
        return tree_search(tree_left(x), v);
    else
        return tree_search(tree_right(x), v);
}

/**
 * 从二叉搜索树中从x为根结点的子树向下查找等于特定值的结点
 * 如果未找到, 返回NULL
 * 迭代实现
 */
template <typename K, typename V>
BSTree_node<K,V> *tree_iterative_search(BSTree_node<K,V> *x, const K &k)
{
	while (x != NULL && k != *tree_key(k)) {
        if (k < *tree_key(k)) {
            x = tree_left(x);
        } else {
            x = tree_right(x);
        }
	}
	return x;
}

#endif
