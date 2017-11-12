#ifndef __rbtree_h
#define __rbtree_h

#include <stddef.h>
#include <assert.h>
#include <memory>

#include "rbtree_base.h"
#include "rbtree_map_node.h"

// 二叉搜索树实现的映射表
template <typename K, typename V>
struct RBTree_map : public RBTree_base {
};

template <typename K, typename V>
RBTree_map_node<K,V> *tree_root(RBTree_map<K,V> *tree)
{
    return tree_map_node<K,V>(tree->root);
}

// 查找二叉搜索树中key等于k的结点, 通过Compare指定偏序关系, 递归方式
template <typename K, typename V, typename Compare = std::less<K>>
RBTree_map_node<K,V> *tree_search(RBTree_map<K,V> *tree, const K &k, Compare comp = Compare())
{
    return tree_map_node<K,V>(tree_search(tree_root(tree), tree_nil(tree), k, comp));
}

// 查找二叉搜索树中key等于k的结点, 通过Compare指定偏序关系, 非递归方式
template <typename K, typename V, typename Compare = std::less<K>>
RBTree_map_node<K,V> *tree_iterative_search(RBTree_map<K,V> *tree, const K &k, Compare comp = Compare())
{
    return tree_map_node<K,V>(tree_iterative_search(tree_root(tree), tree_nil(tree), k, comp));
}

// 向二叉搜索树里插入一个结点z(假设z的value属性已被事先赋值), 
template <typename K, typename V, typename Compare = std::less<K>>
void tree_insert(RBTree_map<K,V> *tree, RBTree_map_node<K,V> *z, Compare comp = Compare()) 
{
    auto y = tree_nil(tree);        // y为要插入位置的父结点
    auto x = tree_root(tree);       // x遍历树
    while (x != tree_nil(tree)) {
        y = x;
        if (comp(*tree_key(z), *tree_key(x)))   // z.key < x.key
            x = tree_left(x);
        else
            x = tree_right(x);
    }

    z->parent = y;
    if (y == tree_nil(tree))
        tree->root = z;                        // 树为空
    else if (comp(*tree_key(z), *tree_key(y)))
        y->left = z;
    else
        y->right =z;

    z->left = tree_nil(tree);
    z->right = tree_nil(tree);
    z->color = RBTree_color::RED;

    tree_insert_fixup(tree, z);
}

// 返回二叉搜索树的最小元素的指针,
template <typename K, typename V>
RBTree_map_node<K,V> *tree_minimum(RBTree_map<K,V> *tree)
{
    return tree_map_node<K,V>(tree_minimum(tree->root), tree_nil(tree));
}

// 返回二叉搜索树的最小元素的指针,
template <typename K, typename V>
RBTree_map_node<K,V> *tree_maximum(RBTree_map<K,V> *tree)
{
    return tree_map_node<K,V>(tree_maximum(tree->root), tree_nil(tree));
}

// 遍历二叉搜索树的所有结点, Function处理data, data类型为std::pair<K,V>
template <typename K, typename V, typename Function>
void tree_for_each(RBTree_map<K,V> *tree, Function fn)
{
    if (tree_is_empty(tree)) {
        return;
    }

    RBTree_map_node<K,V> *x = tree_minimum(tree);
    RBTree_map_node<K,V> *y = tree_maximum(tree);
    while (x != y) {
        fn(*tree_data(x));
        x = tree_successor(x);
    }
    fn(*tree_data(y));
}

// 删除tree中key为k的所有的结点, 返回被删除结点个数
template <typename K, typename V, typename Compare = std::less<K>, typename Deleter = std::default_delete<RBTree_map_node<K,V>>>
int tree_remove(RBTree_map<K,V> *tree, const K &k, Compare comp = Compare(), Deleter del = Deleter())
{
    int i = 0;
    RBTree_map_node<K,V> *x = tree_nil(tree);
    while (true) {
        x = tree_search(tree, k, comp);
        if (x == tree_nil(tree))
            break;

        tree_delete(tree, x);
        del(x);
        ++i;
    }
    return i;
}

// 销毁tree
template <typename K, typename V, typename Deleter = std::default_delete<RBTree_map_node<K,V>>>
void tree_destroy(RBTree_map<K,V> *tree, Deleter del = Deleter())
{
    tree_destroy(tree_root(tree), tree_nil(tree), del);
}

// 清空tree
template <typename K, typename V, typename Deleter = std::default_delete<RBTree_map_node<K,V>>>
void tree_clear(RBTree_map<K,V> *tree, Deleter del = Deleter())
{
    tree_destroy(tree, del);
    tree_init(tree);
}

// 复制tree
template <typename K, typename V, typename Cloner = default_clone_rbtree_map_node<K,V>>
void tree_clone(RBTree_map<K,V> *to, RBTree_map<K,V> *from, Cloner cloner = Cloner())
{
    assert(tree_is_empty(to));

    if (!tree_is_empty(from)) {
        to->root = tree_clone(tree_root(from), tree_nil(from), tree_nil(to), cloner);
        to->root->parent = tree_nil(to);
    }
}

#endif
