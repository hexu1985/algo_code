#include <optional>
#include <iostream>

int main()
{
    std::optional<const char*> s1 = "abc", s2; // 构造函数
    s2 = s1; // 赋值
    s1 = "def"; // 衰变赋值（ U = char[4], T = const char* ）
    std::cout << *s2 << ' ' << *s1 << '\n';
}
