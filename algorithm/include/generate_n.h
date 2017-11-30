#ifndef __generate_n_h
#define __generate_n_h

template <typename OutputIterator, typename Size, typename Generator>
OutputIterator generate_n(OutputIterator first, Size n, Generator gen)
{
    for ( ; n > 0; --n, ++first)
        *first = gen();
    return first;
}

#endif
