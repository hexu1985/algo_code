#ifndef __for_each_h
#define __for_each_h

template <typename InputIterator, typename Function>
Function for_each(InputIterator first, InputIterator last, Function f)
{
    for ( ; first != last; ++first)
        f(*first);
    return f;
}

#endif
