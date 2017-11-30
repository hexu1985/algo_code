#ifndef __copy_backward_h
#define __copy_backward_h

template <typename BidirectionalIterator1, typename BidirectionalIterator2>
BidirectionalIterator2 copy_backward(BidirectionalIterator1 first, BidirectionalIterator1 last, 
        BidirectionalIterator2 result)
{
    while (last != first) 
        *(--result) = *(--last);
    return result;
}

#endif
