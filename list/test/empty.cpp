#include "list.h"
#include <iostream>
 
int main()
{
    DCList<int> numbers;
    list_init(&numbers);
    std::cout << "Initially, numbers.empty(): " << list_is_empty(&numbers) << '\n';
 
    list_insert_tail(&numbers, new DCList_node<int>(42));
    list_insert_tail(&numbers, new DCList_node<int>(13317));
    std::cout << "After adding elements, numbers.empty(): " << list_is_empty(&numbers) << '\n';

    list_destroy(&numbers);
}
