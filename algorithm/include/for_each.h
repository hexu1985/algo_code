#ifndef __for_each_h
#define __for_each_h

template <class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function f)
{
    for ( ; first != last; ++first)
        f(*first);
    return f;
}

#endif
