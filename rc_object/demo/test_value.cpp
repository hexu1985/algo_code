#include "value.h"
#include <utility>
#include <iostream>

using namespace std;

int main()
{
    Value a = 1;
    cout << "a: " << a << endl;
    Value b(a);
    cout << "a: " << a << ", b: " << b << endl;
    a = 2;
    cout << "a: " << a << ", b: " << b << endl;
    Value c = a;
    cout << "a: " << a << ", b: " << b << ", c: " << c << endl;
    c = b;
    cout << "a: " << a << ", b: " << b << ", c: " << c << endl;

    return 0;
}
