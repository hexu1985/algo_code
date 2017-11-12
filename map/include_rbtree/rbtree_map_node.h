#ifndef __rbtree_node_h
#define __rbtree_node_h

#include <utility>
#include "rbtree_node_base.h"

// 二叉查找树结点
// key为索引
// value为数据
template <typename K, typename V>
struct RBTree_map_node : public RBTree_node_base {
	std::pair<K,V> data;

    RBTree_map_node() { } 

    RBTree_map_node(const K &k, const V &v) 
    {
        this->data = std::make_pair(k, v);
    } 

	RBTree_map_node(const std::pair<K,V> &data)
	{
        this->data = data;
	}

    RBTree_map_node(const RBTree_map_node &x)
    {
        this->data = x.data;
    }
};

// 将RBTree_link强转成RBTree_map_node<K, V> *
template <typename K, typename V>
RBTree_map_node<K,V> *tree_map_node(RBTree_link x)
{
    return static_cast<RBTree_map_node<K,V> *>(x);
}

template <typename K, typename V>
RBTree_map_node<K,V> *tree_left(RBTree_map_node<K,V> *x)
{
    return tree_map_node<K,V>(x->left);
}

template <typename K, typename V>
RBTree_map_node<K,V> *tree_right(RBTree_map_node<K,V> *x)
{
    return tree_map_node<K,V>(x->right);
}

template <typename K, typename V>
RBTree_map_node<K,V> *tree_parent(RBTree_map_node<K,V> *x)
{
    return tree_map_node<K,V>(x->parent);
}

// 返回以结点x的后继结点
template <typename K, typename V>
RBTree_map_node<K,V> *tree_successor(RBTree_map_node<K,V> *x, RBTree_link nil)
{
    return tree_map_node<K,V>(tree_successor((RBTree_link)x), nil);
}

// 返回以结点x的前驱结点
template <typename K, typename V>
RBTree_map_node<K,V> *tree_predecessor(RBTree_map_node<K,V> *x, RBTree_link nil)
{
    return tree_map_node<K,V>(tree_predecessor((RBTree_link)x, nil));
}

// 获取data数据成员
template <typename K, typename V>
std::pair<K,V> *tree_data(RBTree_map_node<K,V> *x)
{
    return &(x->data);
}

// 获取key数据成员
template <typename K, typename V>
K *tree_key(RBTree_map_node<K,V> *x)
{
    return &(x->data.first);
}

// 获取value数据成员
template <typename K, typename V>
V *tree_value(RBTree_map_node<K,V> *x)
{
    return &(x->data.second);
}

/**
 * 从二叉搜索树中从x为根结点的子树向下查找等于特定值的结点
 * 如果未找到, 返回NIL
 * 递归实现
 */
template <typename K, typename V, typename Compare = std::less<K>>
RBTree_map_node<K,V> *tree_search(RBTree_map_node<K,V> *x, RBTree_link nil, 
        const K &k, Compare comp = Compare())
{
    if (x == nil)
        return x;

    if (comp(k, *tree_key(x)))      // k < x.key
        return tree_search(tree_left(x), nil, k, comp);
    else if (comp(*tree_key(x), k)) // x.key < k
        return tree_search(tree_right(x), nil, k, comp);
    else                            // x.key == k
        return x;
}

/**
 * 从二叉搜索树中从x为根结点的子树向下查找等于特定值的结点
 * 如果未找到, 返回NULL
 * 迭代实现
 */
template <typename K, typename V, typename Compare = std::less<K>>
RBTree_map_node<K,V> *tree_iterative_search(RBTree_map_node<K,V> *x, RBTree_link nil, 
        const K &k, Compare comp = Compare())
{
	while (x != nil) {
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
template <typename K, typename V, typename Deleter = std::default_delete<RBTree_map_node<K,V>>>
void tree_destroy(RBTree_map_node<K,V> *x, RBTree_link nil, Deleter del = Deleter())
{
    if (x == nil) {
        return;
    }

    tree_destroy(tree_left(x), nil, del);
    tree_destroy(tree_right(x), nil, del);
    del(x);
}

// 默认clone结点方法
template <typename K, typename V>
struct default_clone_rbtree_map_node {
    RBTree_map_node<K,V> *operator ()(RBTree_map_node<K,V> *x)
    {
        assert(x != NULL);
        return new RBTree_map_node<K,V>(*x);
    }
};

// 复制以x结点为根结点的子树
template <typename K, typename V, typename Cloner = default_clone_rbtree_map_node<K,V>>
RBTree_map_node<K,V> *tree_clone(RBTree_map_node<K,V> *x, RBTree_link nil,
        RBTree_link new_nil, Cloner cloner = Cloner())
{
    auto y = cloner(x);
    if (x->left != nil) {
        y->left = tree_clone(tree_map_node<K,V>(x->left), nil, new_nil, cloner);
        y->left->parent = y;
    } else {
        y->left = new_nil;
    }
    if (x->right != nil) {
        y->right = tree_clone(tree_map_node<K,V>(x->right), nil, new_nil, cloner);
        y->right->parent = y;
    } else {
        y->right = new_nil;
    }
    return y;
}

#endif
