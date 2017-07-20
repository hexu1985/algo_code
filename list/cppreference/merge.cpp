#include <iostream>
#include "list.h"
 
std::ostream& operator<<(std::ostream& ostr, const list<int>& list)
{
    for (auto &i : list) {
        ostr << " " << i;
    }
    return ostr;
}
 
int main()
{
    list<int> list1 = { 5,9,0,1,3 };
    list<int> list2 = { 8,7,2,6,4 };
 
    list1.sort();
    list2.sort();
    std::cout << "list1:  " << list1 << "\n";
    std::cout << "list2:  " << list2 << "\n";
    list1.merge(list2);
    std::cout << "merged: " << list1 << "\n";
}
