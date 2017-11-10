#ifndef __map_h
#define __map_h

#include <cstddef>
#include <functional>
#include <stdexcept>
#include <utility>
#include <initializer_list>
#include <limits>

#include "bstree_map.h"
#include "bstree_map_iterator.h"

template <typename Key, typename T, typename Compare = std::less<Key>>
class map: public BSTree_map<Key,T> {
private:
    Compare comp;

    bool key_equals(const Key &k1, const Key &k2) const
    {
        return !comp(k1, k2) && !comp(k2, k1);
    }

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
    typedef BSTree_map_iterator<Key,T> iterator;

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

    map(const map &x): comp(x.comp)
    {
        tree_init(this);
        tree_clone(this, const_cast<map *>(&x));
    }

    map &operator = (const map &x)
    {
        if (this != &x) {
            tree_clear(this);
            tree_clone(this, const_cast<map *>(&x));
        }

        return *this;
    }

    map &operator = (std::initializer_list<value_type> il)
    {
        tree_clear(this);
        for (auto &e : il) {
            tree_insert(this, new BSTree_map_node<Key,T>(e), comp);
        }
    }

    ~map()
    {
        tree_destroy(this);
    }

    iterator begin() const
    {
        return tree_begin(const_cast<map *>(this));
    }

    iterator end() const
    {
        return tree_end(const_cast<map *>(this));
    }

    bool empty() const
    {
        return tree_is_empty(this);
    }

    size_type size() const
    {
        return tree_size(this);
    }

    size_type max_size() const
    {
		return std::numeric_limits<size_type>::max();
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

    mapped_type &at(const key_type &k)
    {
        auto x = tree_iterative_search(this, k, comp);
        if (x == NULL)
            throw std::out_of_range(__func__);
        return *tree_value(x);
    }

    std::pair<iterator, bool> insert(const value_type &val)
    {
        const auto &k = val.first;
        bool ret = false;
        auto x = tree_iterative_search(this, k, comp);
        if (x == NULL) {
            ret = true;
            x = new BSTree_map_node<Key,T>(val);
            tree_insert(this, x, comp);
        }
        return std::make_pair(iterator(this, x), ret);
    }

    iterator insert(iterator pos, const value_type &val)
    {
        auto pair = insert(val);
        return pair.first;
    }

    template <typename InputIterator>
    void insert(InputIterator first, InputIterator last)
    {
        while (first != last) {
            insert(*first);
            ++first;
        }
    }

    iterator erase(iterator pos)
    {
        assert(pos != end());
        auto x = pos.get_node();
        ++pos;
        tree_delete(this, x);
        delete x;
        return pos;
    }

    size_type erase(const key_type &k)
    {
        return tree_remove(this, k, comp);
    }

    iterator erase(iterator first, iterator last)
    {
        while (first != last) {
            first = erase(first);
        }
        return last;
    }

    void swap(map &x)
    {
        tree_swap(this, &x);
    }

    void clear()
    {
        tree_clear(this);
    }

    key_compare key_comp() const
    {
        return comp;
    }

    value_compare value_comp() const
    {
        return value_compare(comp);
    }

    iterator find(const key_type &k)
    {
        auto x = tree_iterative_search(this, k, comp);
        if (x == NULL)
            return end();
        return iterator(this, x);
    }

    size_type count(const key_type &k) const
    {
        auto x = tree_iterative_search(const_cast<map *>(this), k, comp);
        if (x == NULL)
            return 0;
        auto it = iterator(const_cast<map *>(this), x);
        ++it;
        int i = 1;
        while (it != end() && key_equals(it->first, k)) {
            ++it;
            ++i;
        }
        return i;
    }
};

#endif
