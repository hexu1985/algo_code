#ifndef __rbtree_map_node_h
#define __rbtree_map_node_h

#include "rbtree_map_node.h"
#include "rbtree_map.h"

template <typename K, typename V>
struct RBTree_map_iterator {
    RBTree_map<K,V> *tree;
    RBTree_map_node<K,V> *node;

    typedef std::pair<K,V> value_type;
    typedef std::pair<K,V> *pointer;
    typedef std::pair<K,V> &reference;
    typedef ptrdiff_t difference_type;
    typedef std::bidirectional_iterator_tag iterator_category;

    typedef RBTree_map_iterator<K,V> this_type;

    RBTree_map_iterator(): tree(NULL), node(NULL) {}

    explicit RBTree_map_iterator(RBTree_map<K,V> *tree, RBTree_link link): tree(tree), node(tree_map_node<K,V>(link)) {}
    
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
        assert(node != NULL && tree != NULL && node != tree_nil(tree));
        node = tree_map_node<K,V>(tree_successor(node, tree_nil(tree)));
        return *this;
    }

    this_type operator ++(int)
    {
        assert(node != NULL && tree != NULL && node != tree_nil(tree));
        this_type tmp(*this);
        node = tree_map_node<K,V>(tree_successor(node, tree_nil(tree)));
        return tmp;
    }

    this_type &operator --()
    {
        if (node)
            node = tree_map_node<K,V>(tree_predecessor(node, tree_nil(tree)));
        else        // reach end
            node = tree_map_node<K,V>(tree_maximum(tree));
        return *this;
    }

    this_type operator --(int)
    {
        this_type tmp(*this);
        if (node)
            node = tree_map_node<K,V>(tree_predecessor(node, tree_nil(tree)));
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

    RBTree_map_node<K,V> *get_node()
    {
        return node;
    }
};

template <typename K, typename V>
RBTree_map_iterator<K,V> tree_begin(RBTree_map<K,V> *tree)
{
    assert(tree != NULL);
    if (tree_is_empty(tree))
        return RBTree_map_iterator<K,V>(tree, tree_nil(tree));

    return RBTree_map_iterator<K,V>(tree, tree_minimum(tree));
}

template <typename K, typename V>
RBTree_map_iterator<K,V> tree_end(RBTree_map<K,V> *tree)
{
    assert(tree != NULL);
    return RBTree_map_iterator<K,V>(tree, tree_nil(tree));
}

#endif
