#include "list.h"
#include <iostream>
#include <iomanip>
 
int main()
{
    list<std::string> numbers;
 
    numbers.push_back("abc");
    std::string s = "def";
    numbers.push_back(std::move(s));
 
    std::cout << "list holds: ";
    for (auto&& i : numbers) std::cout << std::quoted(i) << ' ';
    std::cout << "\nMoved-from string holds " << std::quoted(s) << '\n';
}
