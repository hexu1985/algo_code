#ifndef __bstree_h
#define __bstree_h

#include <stddef.h>
#include <assert.h>

template <typename K, typename V>
struct BSTree_map : public BSTree_base {
};

template <typename K, typename V, typename Compare = std::less<K>>
BSTree_link tree_search(BSTree_map<K,V> *tree, const K &k, Compare comp = Compare())
{
    return tree_search(tree_node<K,V>(tree->root), k, comp);
}

template <typename K, typename V, typename Compare = std::less<K>>
BSTree_link tree_iterative_search(BSTree_map<K,V> *tree, const K &k, Compare comp = Compare())
{
    return tree_iterative_search(tree_node<K,V>(tree->root), k, comp);
}

// 向二叉搜索树里插入一个结点z(假设z的value属性已被事先赋值), 
// 并且z->left和z->right指向NIL
template <typename K, typename V, typename Compare = std::less<K>>
void tree_insert(BSTree_map<K,V> *tree, BSTree_map_node<K,V> *z, Compare comp = Compare()) 
{
    z->left = z->right = NULL;

    BSTree_map_node<K,V> *y = NULL;            // y为要插入位置的父结点
    BSTree_map_node<K,V> *x = tree_node<K,V>(tree->root);    // x遍历树
    while (x != NULL) {
        y = x;
        if (comp(*tree_key(z), *tree_key(x)))  // z.key < x.key
            x = tree_left(x);
        else
            x = tree_right(x);
    }

    z->parent = y;
    if (y == NULL)
        tree->root = z;                        // 树为空
    else if (comp(*tree_key(z), *tree_key(x)))
        y->left = z;
    else
        y->right =z;
}

template <typename K, typename V, typename Function>
void tree_for_each(BSTree_map<K,V> *tree, Function fn)
{
    if (tree_is_empty(tree)) {
        return;
    }

    BSTree_map_node<K,V> *x = tree_minimum(tree);
}

#endif
