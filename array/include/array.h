#ifndef __array_h
#define __array_h

#include <cstddef>
#include <stdexcept>
#include <initializer_list>
#include "array_view.h"

template <typename T, size_t N>
class array: public Array_view<T> {
private:
    T data_[N];

    typedef Array_view<T> base;

public:
    typedef T value_type;
    typedef T &reference;
    typedef T *pointer;
    typedef ptrdiff_t difference_type;
    typedef size_t size_type;
    typedef T *iterator;

    array(): base(data_, N) {}

    array(std::initializer_list<value_type> il): base(data_, N)
    {
        size_t i = 0;
        for (auto &e : il) {
            if (i >= N) {
                break;
            }
            this->operator[](i) = e;
            i++;
        }
    }

    reference at(size_t n) 
    {
        if ((int) n >= this->size()) {
            throw std::out_of_range(__func__);
        }

        return this->operator[](n);
    }

    bool empty() const
    {
        return this->size() == 0;
    }

    size_type max_size() const
    {
        return this->size();
    }

    void swap(array &x)
    {
        using std::swap;
        for (int i = 0; i < this->size(); i++) {
            swap(this->operator[](i), x[i]);
        }
    }
};

#endif
