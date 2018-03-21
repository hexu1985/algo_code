#include <optional>
#include <iostream>
int main()
{
    std::optional<int> opt = {};
 
    try {
        int n = opt.value();
    } catch(const std::exception& e) {
        std::cout << e.what() << '\n';
    }
}
