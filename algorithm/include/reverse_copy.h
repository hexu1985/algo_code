#ifndef __reverse_copy_h
#define __reverse_copy_h

template <typename BidirectionalIterator, typename OutputIterator>
OutputIterator reverse_copy(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result)
{
    while (first != last) {
        --last;
        *result = *last;
        ++result;
    }
    return result;
}

#endif

