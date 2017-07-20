#include <iostream>
#include "list.h"
 
std::ostream& operator<<(std::ostream& ostr, const list<int>& list)
{
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}
 
int main ()
{
    list<int> list1 = { 1, 2, 3, 4, 5 };
    list<int> list2 = { 10, 20, 30, 40, 50 };
 
    auto it = list1.begin();
    std::advance(it, 2);
 
    list1.splice(it, list2);
 
    std::cout << "list1: " << list1 << "\n";
    std::cout << "list2: " << list2 << "\n";
 
    list2.splice(list2.begin(), list1, it, list1.end());
 
    std::cout << "list1: " << list1 << "\n";
    std::cout << "list2: " << list2 << "\n";
}
