#ifndef __print_all_h
#define __print_all_h

template <typename RandomAccessIterator>
void print_all(RandomAccessIterator first, RandomAccessIterator last)
{
    std::copy(first, last, std::ostream_iterator<typename std::iterator_traits<RandomAccessIterator>::value_type>(std::cout, ", ")); 
    std::cout << std::endl;
}

#endif
