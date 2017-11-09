#ifndef __generate_h
#define __generate_h

template <typename ForwardIterator, typename Generator>
void generate(ForwardIterator first, ForwardIterator last, Generator gen)
{
    for ( ; first != last; ++first)
        *first = gen();
}

#endif
