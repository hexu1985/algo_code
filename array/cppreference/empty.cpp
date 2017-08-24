#include "array.h"
#include <iostream>
 
int main()
{
    array<int, 4> numbers {3, 1, 4, 1};
    array<int, 0> no_numbers;
 
    std::cout << "numbers.empty(): " << numbers.empty() << '\n';
    std::cout << "no_numbers.empty(): " << no_numbers.empty() << '\n';
}
