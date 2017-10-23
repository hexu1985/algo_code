#ifndef __find_end_h
#define __find_end_h

#include <iterator>

template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 __find_end(ForwardIterator1 first1, ForwardIterator1 last1, 
        ForwardIterator2 first2, ForwardIterator2 last2,
        std::forward_iterator_tag, std::forward_iterator_tag)
{
    if (first2 == last2)
        return last1;
    else {
        ForwardIterator1 result = last1;
        while (true) {
            ForwardIterator1 new_result = search(first1, last1, first2, last2);
            if (new_result == last1) {
                return result;
            } else {
                result = new_result;
                first1 = new_result;
                ++first1;
            }
        }
    }
}

template <typename BidirectionalIterator1, typename BidirectionalIterator2>
BidirectionalIterator1 __find_end(BidirectionalIterator1 first1, BidirectionalIterator1 last1, 
        BidirectionalIterator2 first2, BidirectionalIterator2 last2,
        std::bidirectional_iterator_tag, std::bidirectional_iterator_tag)
{
    typedef std::reverse_iterator<BidirectionalIterator1> reviter1; 
    typedef std::reverse_iterator<BidirectionalIterator2> reviter2; 

    reviter1 rlast1(first1);
    reviter2 rlast2(first2);

    reviter1 rresult = search(reviter1(last1), rlast1, reviter2(last2), rlast2);

    if (rresult == rlast1)
        return last1;
    else {
        BidirectionalIterator1 result = rresult.base();
        std::advance(result, -std::distance(first2, last2));
        return result;
    }
}

template <typename ForwardIterator1, typename ForwardIterator2>
ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, 
        ForwardIterator2 first2, ForwardIterator2 last2)
{
    typedef typename std::iterator_traits<ForwardIterator1>::iterator_category category1;
    typedef typename std::iterator_traits<ForwardIterator2>::iterator_category category2;

    return __find_end(first1, last1, first2, last2, category1(), category2());
}

template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1 __find_end(ForwardIterator1 first1, ForwardIterator1 last1, 
        ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred,
        std::forward_iterator_tag, std::forward_iterator_tag)
{
    if (first2 == last2)
        return last1;
    else {
        ForwardIterator1 result = last1;
        while (true) {
            ForwardIterator1 new_result = search(first1, last1, first2, last2, pred);
            if (new_result == last1) {
                return result;
            } else {
                result = new_result;
                first1 = new_result;
                ++first1;
            }
        }
    }
}

template <typename BidirectionalIterator1, typename BidirectionalIterator2, typename BinaryPredicate>
BidirectionalIterator1 __find_end(BidirectionalIterator1 first1, BidirectionalIterator1 last1, 
        BidirectionalIterator2 first2, BidirectionalIterator2 last2, BinaryPredicate pred,
        std::bidirectional_iterator_tag, std::bidirectional_iterator_tag)
{
    typedef std::reverse_iterator<BidirectionalIterator1> reviter1; 
    typedef std::reverse_iterator<BidirectionalIterator2> reviter2; 

    reviter1 rlast1(first1);
    reviter2 rlast2(first2);

    reviter1 rresult = search(reviter1(last1), rlast1, reviter2(last2), rlast2, pred);

    if (rresult == rlast1)
        return last1;
    else {
        BidirectionalIterator1 result = rresult.base();
        std::advance(result, -std::distance(first2, last2));
        return result;
    }
}

template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
ForwardIterator1 find_end(ForwardIterator1 first1, ForwardIterator1 last1, 
        ForwardIterator2 first2, ForwardIterator2 last2, BinaryPredicate pred)
{
    typedef typename std::iterator_traits<ForwardIterator1>::iterator_category category1;
    typedef typename std::iterator_traits<ForwardIterator2>::iterator_category category2;

    return __find_end(first1, last1, first2, last2, pred, category1(), category2());
}

#endif
