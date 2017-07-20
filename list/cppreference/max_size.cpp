#include <iostream>
#include "list.h"
 
int main()
{
    list<char> s;
    std::cout << "Maximum size of a 'list' is " << s.max_size() << "\n";
}
