#include "list.h"
#include <iostream>
 
int main()
{
    list<int> numbers;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
 
    numbers.push_back(42);
    numbers.push_back(13317); 
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
}
