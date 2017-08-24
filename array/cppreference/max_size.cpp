#include <iostream>
#include "array.h"
 
int main()
{
    array<char, 10> s;
    std::cout << "Maximum size of a 'array' is " << s.max_size() << "\n";
}
