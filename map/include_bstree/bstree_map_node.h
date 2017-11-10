#ifndef __bstree_node_h
#define __bstree_node_h

#include <utility>
#include "bstree_node_base.h"

// 二叉查找树结点
// key为索引
// value为数据
template <typename K, typename V>
struct BSTree_map_node : public BSTree_node_base {
	std::pair<K,V> data;

    BSTree_map_node() { } 

    BSTree_map_node(const K &k, const V &v) 
    {
        this->data = std::make_pair(k, v);
    } 

	BSTree_map_node(const std::pair<K,V> &data)
	{
        this->data = data;
	}

    BSTree_map_node(const BSTree_map_node &x)
    {
        this->data = x.data;
    }
};

// 将BSTree_link强转成BSTree_map_node<K, V> *
template <typename K, typename V>
BSTree_map_node<K,V> *tree_map_node(BSTree_link x)
{
    return static_cast<BSTree_map_node<K,V> *>(x);
}

template <typename K, typename V>
BSTree_map_node<K,V> *tree_left(BSTree_map_node<K,V> *x)
{
    return tree_map_node<K,V>(x->left);
}

template <typename K, typename V>
BSTree_map_node<K,V> *tree_right(BSTree_map_node<K,V> *x)
{
    return tree_map_node<K,V>(x->right);
}

template <typename K, typename V>
BSTree_map_node<K,V> *tree_parent(BSTree_map_node<K,V> *x)
{
    return tree_map_node<K,V>(x->parent);
}

// 返回以结点x的后继结点
template <typename K, typename V>
BSTree_map_node<K,V> *tree_successor(BSTree_map_node<K,V> *x)
{
    return tree_map_node<K,V>(tree_successor((BSTree_link)x));
}

// 返回以结点x的前驱结点
template <typename K, typename V>
BSTree_map_node<K,V> *tree_predecessor(BSTree_map_node<K,V> *x)
{
    return tree_map_node<K,V>(tree_predecessor((BSTree_link)x));
}

// 获取data数据成员
template <typename K, typename V>
std::pair<K,V> *tree_data(BSTree_map_node<K,V> *x)
{
    return &(x->data);
}

// 获取key数据成员
template <typename K, typename V>
K *tree_key(BSTree_map_node<K,V> *x)
{
    return &(x->data.first);
}

// 获取value数据成员
template <typename K, typename V>
V *tree_value(BSTree_map_node<K,V> *x)
{
    return &(x->data.second);
}

/**
 * 从二叉搜索树中从x为根结点的子树向下查找等于特定值的结点
 * 如果未找到, 返回NIL
 * 递归实现
 */
template <typename K, typename V, typename Compare = std::less<K>>
BSTree_map_node<K,V> *tree_search(BSTree_map_node<K,V> *x, const K &k, Compare comp = Compare())
{
    if (x == NULL)
        return x;

    if (comp(k, *tree_key(x)))      // k < x.key
        return tree_search(tree_left(x), k);
    else if (comp(*tree_key(x), k)) // x.key < k
        return tree_search(tree_right(x), k);
    else                            // x.key == k
        return x;
}

/**
 * 从二叉搜索树中从x为根结点的子树向下查找等于特定值的结点
 * 如果未找到, 返回NULL
 * 迭代实现
 */
template <typename K, typename V, typename Compare = std::less<K>>
BSTree_map_node<K,V> *tree_iterative_search(BSTree_map_node<K,V> *x, const K &k, Compare comp = Compare())
{
	while (x != NULL) {
        if (comp(k, *tree_key(x))) {        // k < x.key
            x = tree_left(x);
        } else if (comp(*tree_key(x), k)) { // x.key < k
            x = tree_right(x);
        } else {                            // x.key == k
            break;
        }
	}
	return x;
}

// 销毁x结点指向的子树
template <typename K, typename V, typename Deleter = std::default_delete<BSTree_map_node<K,V>>>
void tree_destroy(BSTree_map_node<K,V> *x, Deleter del = Deleter())
{
    if (x == NULL) {
        return;
    }

    tree_destroy(tree_left(x), del);
    tree_destroy(tree_right(x), del);
    del(x);
}

// 默认clone结点方法
template <typename K, typename V>
struct default_clone_bstree_map_node {
    BSTree_map_node<K,V> *operator ()(BSTree_map_node<K,V> *x)
    {
        assert(x != NULL);
        return new BSTree_map_node<K,V>(*x);
    }
};

// 复制以x结点为根结点的子树
template <typename K, typename V, typename Cloner = default_clone_bstree_map_node<K,V>>
BSTree_map_node<K,V> *tree_clone(BSTree_map_node<K,V> *x, Cloner cloner = Cloner())
{
    auto y = cloner(x);
    if (x->left != NULL) {
        y->left = tree_clone(tree_map_node<K,V>(x->left), cloner);
        y->left->parent = y;
    } else {
        y->left = NULL;
    }
    if (x->right != NULL) {
        y->right = tree_clone(tree_map_node<K,V>(x->right), cloner);
        y->right->parent = y;
    } else {
        y->right = NULL;
    }
    return y;
}

#endif
