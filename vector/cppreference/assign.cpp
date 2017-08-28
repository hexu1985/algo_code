#include "vector.h"
#include <iostream>
 
int main()
{
    vector<char> characters;
 
    characters.assign(5, 'a');
 
    for (char c : characters) {
        std::cout << c << '\n';
    } 
 
    return 0;
}
