#include <list>
#include <iostream>
 
int main()
{
    std::list<char> characters;
 
    characters.assign(5, 'a');
 
    for (char c : characters) {
        std::cout << c << '\n';
    } 
 
    return 0;
}
