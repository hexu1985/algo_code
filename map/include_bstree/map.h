#ifndef __map_h
#define __map_h

#include <cstddef>
#include <type_traits>
#include <initializer_list>
#include <limits>

#include "bstree_map.h"
#include "bstree_map_iterator.h"

template <typename Key, typename T, typename Compare = std::less<Key>>
class map: public BSTree_map<Key, T> {
private:
    Compare comp;

public:
    typedef Key key_type;
    typedef T mapped_type;
    typedef std::pair<const key_type, mapped_type> value_type;
    typedef Compare key_compare;

    struct value_compare: public std::binary_function<value_type, value_type, bool> {
        Compare comp;
        value_compare(Compare comp): comp(comp) {}

        bool operator ()(const value_type &x, const value_type &y) const
        {
            return comp(x.first, y.first);
        }
    };

    typedef value_type &reference;
    typedef value_type *pointer;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef BSTree_map_iterator<Key, T> iterator;

    map(const key_compare &comp = key_compare()): comp(comp)
    {
        tree_init(this);
    }

    template <typename InputIterator>
    map(InputIterator first, InputIterator last, const key_compare &comp = key_compare()): comp(comp)
    {
        tree_init(this);
        while (first != last) {
            tree_insert(this, new BSTree_map_node<Key,T>(*first), comp);
            ++first;
        }
    }

    map(std::initializer_list<value_type> il, const key_compare &comp = key_compare()): comp(comp)
    {
        tree_init(this);
        for (auto &e : il) {
            tree_insert(this, new BSTree_map_node<Key,T>(e), comp);
        }
    }

    iterator begin()
    {
        return tree_begin(this);
    }

    iterator end()
    {
        return tree_end(this);
    }

	mapped_type &operator [](const key_type &k)
	{
        auto x = tree_iterative_search(this, k, comp);
        if (x == NULL) {
            x = new BSTree_map_node<Key,T>(k, mapped_type());
            tree_insert(this, x, comp);
        }
        return *tree_value(x);
	}
};

#endif
