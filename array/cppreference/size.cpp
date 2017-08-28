#include "array.h"
#include <iostream>
 
int main()
{ 
    array<int, 4> nums {1, 3, 5, 7};
 
    std::cout << "nums contains " << nums.size() << " elements.\n";
}
