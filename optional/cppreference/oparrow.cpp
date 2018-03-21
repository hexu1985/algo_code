#include <optional>
#include <iostream>
#include <string>
 
int main()
{
    using namespace std::string_literals;
 
    std::optional<int> opt1 = 1;
    std::cout<< "opt1: "  << *opt1 << '\n';
 
    *opt1 = 2;
    std::cout<< "opt1: "  << *opt1 << '\n';
 
    std::optional<std::string> opt2 = "abc"s;
    std::cout<< "opt2: " << *opt2 << " size: " << opt2->size() << '\n';
 
    // 你能通过在到 optional 的右值上调用 operator* “取”其所含值
 
    auto taken = *std::move(opt2);
    std::cout << "taken: " << taken << " opt2: " << *opt2 << "size: " << opt2->size()  << '\n';
}
