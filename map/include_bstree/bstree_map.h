#ifndef __bstree_h
#define __bstree_h

#include <stddef.h>
#include <assert.h>
#include <memory>

#include "bstree_base.h"
#include "bstree_map_node.h"

// 二叉搜索树实现的映射表
template <typename K, typename V>
struct BSTree_map : public BSTree_base {
};

template <typename K, typename V>
BSTree_map_node<K,V> *tree_root(BSTree_map<K,V> *tree)
{
    return tree_map_node<K,V>(tree->root);
}

// 查找二叉搜索树中key等于k的结点, 通过Compare指定偏序关系, 递归方式
template <typename K, typename V, typename Compare = std::less<K>>
BSTree_map_node<K,V> *tree_search(BSTree_map<K,V> *tree, const K &k, Compare comp = Compare())
{
    return tree_map_node<K,V>(tree_search(tree_root(tree), k, comp));
}

// 查找二叉搜索树中key等于k的结点, 通过Compare指定偏序关系, 非递归方式
template <typename K, typename V, typename Compare = std::less<K>>
BSTree_map_node<K,V> *tree_iterative_search(BSTree_map<K,V> *tree, const K &k, Compare comp = Compare())
{
    return tree_map_node<K,V>(tree_iterative_search(tree_root(tree), k, comp));
}

// 向二叉搜索树里插入一个结点z(假设z的value属性已被事先赋值), 
template <typename K, typename V, typename Compare = std::less<K>>
void tree_insert(BSTree_map<K,V> *tree, BSTree_map_node<K,V> *z, Compare comp = Compare()) 
{
    z->left = z->right = NULL;

    BSTree_map_node<K,V> *y = NULL;             // y为要插入位置的父结点
    BSTree_map_node<K,V> *x = tree_root(tree);  // x遍历树
    while (x != NULL) {
        y = x;
        if (comp(*tree_key(z), *tree_key(x)))   // z.key < x.key
            x = tree_left(x);
        else
            x = tree_right(x);
    }

    z->parent = y;
    if (y == NULL)
        tree->root = z;                        // 树为空
    else if (comp(*tree_key(z), *tree_key(y)))
        y->left = z;
    else
        y->right =z;
}

// 返回二叉搜索树的最小元素的指针,
template <typename K, typename V>
BSTree_map_node<K,V> *tree_minimum(BSTree_map<K,V> *tree)
{
    return tree_map_node<K,V>(tree_minimum(tree->root));
}

// 返回二叉搜索树的最小元素的指针,
template <typename K, typename V>
BSTree_map_node<K,V> *tree_maximum(BSTree_map<K,V> *tree)
{
    return tree_map_node<K,V>(tree_maximum(tree->root));
}

// 遍历二叉搜索树的所有结点, Function处理data, data类型为std::pair<K,V>
template <typename K, typename V, typename Function>
void tree_for_each(BSTree_map<K,V> *tree, Function fn)
{
    if (tree_is_empty(tree)) {
        return;
    }

    BSTree_map_node<K,V> *x = tree_minimum(tree);
    BSTree_map_node<K,V> *y = tree_maximum(tree);
    while (x != y) {
        fn(*tree_data(x));
        x = tree_successor(x);
    }
    fn(*tree_data(y));
}

// 删除tree中key为k的所有的结点, 返回被删除结点个数
template <typename K, typename V, typename Compare = std::less<K>, typename Deleter = std::default_delete<BSTree_map_node<K,V>>>
int tree_remove(BSTree_map<K,V> *tree, const K &k, Compare comp = Compare(), Deleter del = Deleter())
{
    int i = 0;
    BSTree_map_node<K,V> *x = NULL;
    while (true) {
        x = tree_search(tree, k, comp);
        if (x == NULL)
            break;

        tree_delete(tree, x);
        del(x);
        ++i;
    }
    return i;
}

// 销毁tree
template <typename K, typename V, typename Deleter = std::default_delete<BSTree_map_node<K,V>>>
void tree_destroy(BSTree_map<K,V> *tree, Deleter del = Deleter())
{
    tree_destroy(tree_root(tree), del);
}

// 清空tree
template <typename K, typename V, typename Deleter = std::default_delete<BSTree_map_node<K,V>>>
void tree_clear(BSTree_map<K,V> *tree, Deleter del = Deleter())
{
    tree_destroy(tree, del);
    tree_init(tree);
}

#endif
