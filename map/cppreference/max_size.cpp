#include <iostream>
#include "map.h"
 
int main()
{
    map<char,char> s;
    std::cout << "Maximum size of a 'map' is " << s.max_size() << "\n";
}
