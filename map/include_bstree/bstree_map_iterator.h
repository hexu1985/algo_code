#ifndef __bstree_map_node_h
#define __bstree_map_node_h

#include "bstree_map_node.h"
#include "bstree_map.h"

template <typename K, typename V>
struct BSTree_map_iterator {
    BSTree_map<K,V> *tree;
    BSTree_map_node<K,V> *node;

    typedef std::pair<K,V> value_type;
    typedef std::pair<K,V> *pointer;
    typedef std::pair<K,V> &reference;
    typedef ptrdiff_t difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;

    typedef BSTree_map_iterator<K,V> this_type;

    BSTree_map_iterator(): tree(NULL), node(NULL) {}

    explicit BSTree_map_iterator(BSTree_map<K,V> *tree, BSTree_link link): tree(tree), node(tree_map_node<K,V>(link)) {}
    
    reference operator *() const
    {
        return *tree_data(node);
    }

    pointer operator ->() const
    {
        return tree_data(node);
    }

    this_type &operator ++()
    {
        assert(node != NULL);
        node = tree_map_node<K,V>(tree_successor(node));
        return *this;
    }

    this_type operator ++(int)
    {
        assert(node != NULL);
        this_type tmp(*this);
        node = tree_map_node<K,V>(tree_successor(node));
        return tmp;
    }

    this_type &operator --()
    {
        if (node)
            node = tree_map_node<K,V>(tree_predecessor(node));
        else        // reach end
            node = tree_map_node<K,V>(tree_maximum(tree));
        return *this;
    }

    this_type operator --(int)
    {
        this_type tmp(*this);
        if (node)
            node = tree_map_node<K,V>(tree_predecessor(node));
        else        // reach end
            node = tree_map_node<K,V>(tree_maximum(tree));
        return tmp;
    }

    bool operator ==(const this_type &other) const
    {
        return (tree == other.tree && node == other.node);
    }

    bool operator !=(const this_type &other) const
    {
        return !(*this == other);
    }

    BSTree_map_node<K,V> *get_node()
    {
        return node;
    }
};

template <typename K, typename V>
BSTree_map_iterator<K,V> tree_begin(BSTree_map<K,V> *tree)
{
    assert(tree != NULL);
    if (tree_is_empty(tree))
        return BSTree_map_iterator<K,V>(tree, NULL);

    return BSTree_map_iterator<K,V>(tree, tree_minimum(tree));
}

template <typename K, typename V>
BSTree_map_iterator<K,V> tree_end(BSTree_map<K,V> *tree)
{
    assert(tree != NULL);
    return BSTree_map_iterator<K,V>(tree, NULL);
}

#endif
