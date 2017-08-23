#include <iostream>
#include <functional>
#include "dclist.h"
#include "dclist_util.h"
 
int main()
{
    DCList<int> list;
    list_init(&list, { 8,7,5,9,0,1,3,2,6,4 });
 
    std::cout << "before:     " << list << "\n";
    list_sort(&list);
    std::cout << "ascending:  " << list << "\n";
    list_sort(&list, std::greater<int>());
    std::cout << "descending: " << list << "\n";
}
