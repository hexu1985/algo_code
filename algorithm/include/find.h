#ifndef __find_h
#define __find_h

template <typename InputIterator, typename T>
InputIterator find(InputIterator first, InputIterator last, const T &val)
{
    while (first != last && *first != val) {
        ++first;
    }

    return first;
}

#endif
