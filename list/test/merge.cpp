#include <iostream>
#include "dclist.h"
#include "dclist_util.h"
 
int main()
{
    DCList<int> list1;
    list_init(&list1, { 5,9,0,1,3 });
    DCList<int> list2;
    list_init(&list2, { 8,7,2,6,4 });
 
    list_sort(&list1);
    list_sort(&list2);
    std::cout << "list1:  " << list1 << "\n";
    std::cout << "list2:  " << list2 << "\n";
    list_merge(&list1, &list2);
    std::cout << "merged: " << list1 << "\n";
}
