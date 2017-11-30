#ifndef __rotate_copy_h
#define __rotate_copy_h

#include "copy.h"

template <typename ForwardIterator, typename OutputIterator>
OutputIterator rotate_copy(ForwardIterator first, ForwardIterator middle, ForwardIterator last, 
        OutputIterator result)
{
    return _copy(first, middle, _copy(middle, last, result));
}

#endif
