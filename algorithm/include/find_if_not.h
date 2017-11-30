#ifndef __find_if_not_h
#define __find_if_not_h

template <typename InputIterator, typename UnaryPredicate>
InputIterator find_if_not(InputIterator first, InputIterator last, UnaryPredicate pred)
{
    while (first != last && pred(*first)) {
        ++first;
    }

    return first;
}

#endif
