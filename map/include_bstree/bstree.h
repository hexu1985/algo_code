#ifndef __bstree_h
#define __bstree_h

#include <stddef.h>
#include <assert.h>

template <typename K, typename V>
struct BSTree : public BSTree_base {
};

template <typename K, typename V>
BSTree_link tree_iterative_search(BSTree<K,V> *tree, const K &k)
{
    return tree_iterative_search(tree_node<K,V>(tree->root), k);
}

template <typename K, typename V>
BSTree_link tree_search(BSTree<K,V> *tree, const K &k)
{
    return tree_search(tree_node<K,V>(tree->root), k);
}

// 向二叉搜索树里插入一个结点z(假设z的value属性已被事先赋值), 
// 并且z->left和z->right指向NIL
template <typename K, typename V>
void tree_insert(BSTree<K,V> *tree, BSTree_node<K,V> *z) 
{
    z->left = z->right = NULL;

    auto y = (BSTree_link) NULL;            // y为要插入位置的父结点
    auto x = tree_node<K,V>(tree->root);    // x遍历树
    while (x != NULL) {
        y = x;
        if (*tree_key(z) < *tree_key(x))
            x = tree_left(x);
        else
            x = tree_right(x);
    }

    z->parent = y;
    if (y == NULL)
        tree.root = z;                      // 树为空
    else if (z->value < tree_link_cast<T>(y)->value)
        y->left = z;
    else
        y->right =z;
}

// 删除tree中key为k的所有的结点
template <typename K, typename V, typename Deleter = std::default_delete<BSTree_node<K,V>>>
int tree_remove(BSTree<K,V> *tree, const K &k, Deleter del = Deleter())
{
    int i = 0;
    BSTree_node<K,V> *x = NULL;
    while (true) {
        x = tree_search(tree, k);
        if (x == NULL)
            return i;

        tree_delete(tree, x);
        del(x);
        ++i;
    }
}

#endif
