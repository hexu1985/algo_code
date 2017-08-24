#include "array.h"
#include <iostream>
 
int main()
{
    array<char, 6> letters {'o', 'm', 'g', 'w', 't', 'f'};
    if (!letters.empty()) {
        std::cout << "The last character is: " << letters.back() << '\n';
    }  
}
