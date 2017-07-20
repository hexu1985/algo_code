#include "list.h"
#include <iostream>
 
int main()
{
    list<char> characters;
 
    characters.assign(5, 'a');
 
    for (char c : characters) {
        std::cout << c << '\n';
    } 
 
    return 0;
}
