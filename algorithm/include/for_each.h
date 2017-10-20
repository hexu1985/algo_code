#ifndef __for_each_h
#define __for_each_h

#include <iostream>

template <class InputIterator, class Function>
Function for_each(InputIterator first, InputIterator last, Function f)
{
    std::cout << __FILE__ << ":" << __LINE__ << "," << __func__ << std::endl;
    for ( ; first != last; ++first)
        f(*first);
    return f;
}

#endif
