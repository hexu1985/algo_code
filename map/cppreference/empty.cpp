#include "map.h"
#include <iostream>
#include <utility>
 
int main()
{
    map<int,int> numbers;
    std::cout << "Initially, numbers.empty(): " << numbers.empty() << '\n';
 
    numbers.emplace(42, 13);
    numbers.insert(std::make_pair(13317, 123)); 
    std::cout << "After adding elements, numbers.empty(): " << numbers.empty() << '\n';
}
