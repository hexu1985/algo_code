#ifndef __partition_point_h
#define __partition_point_h

template <class ForwardIterator, class UnaryPredicate>
ForwardIterator partition_point(ForwardIterator first, ForwardIterator last,
        UnaryPredicate pred)
{
    auto n = std::distance(first, last);
    while (n > 0) {
        ForwardIterator it = first;
        auto step = n/2;
        std::advance(it, step);
        if (pred(*it)) {
            first = ++it; 
            n -= step+1; 
        } else 
            n = step;
    }
    return first;
}

#endif

