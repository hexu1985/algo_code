#include <optional>
#include <iostream>
#include <string>

int main()
{
    std::optional<int> o1, // 空
                       o2 = 1, // 从右值初始化
                       o3 = o2; // 复制构造函数
 
    // 调用 std::string( initializer_list<CharT> ) 构造函数
    std::optional<std::string> o4(std::in_place, {'a', 'b', 'c'});
 
    // 调用 std::string( size_type count, CharT ch ) 构造函数
    std::optional<std::string> o5(std::in_place, 3, 'A');
 
    // 从 std::string 移动构造，用推导指引拾取类型
 
    std::optional o6(std::string{"deduction"});
 
    std::cout << *o2 << ' ' << *o3 << ' ' << *o4 << ' ' << *o5  << ' ' << *o6 << '\n';
}
