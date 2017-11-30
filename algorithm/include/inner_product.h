#ifndef __inner_product_h
#define __inner_product_h

template <typename InputIterator1, typename InputIterator2, typename T>
T inner_product(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init)
{
    for ( ; first1 != last1; ++first1, ++first2) {
        init = init + (*first1 * *first2);
    }
    return init;
}

template <typename InputIterator1, typename InputIterator2, typename T, typename BinaryOperation1, typename BinaryOperation2>
T inner_product (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, T init,
                 BinaryOperation1 binary_op1, BinaryOperation2 binary_op2)
{
    for ( ; first1 != last1; ++first1, ++first2) {
        init = binary_op1(init, binary_op2(*first1, *first2));
    }
    return init;
}

#endif
