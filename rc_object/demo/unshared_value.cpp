#include "unshared_value.h"
#include <utility>
#include <iostream>
#include <memory>
#include "rc_ptr.h"

typedef RCPtr<UnsharedValue> ValuePtr;

using namespace std;

int main()
{
    std::auto_ptr<UnsharedValue> ptr(new UnsharedValue(1));
    ValuePtr a(ptr.get());
    cout << "a: " << *a << endl;
    ValuePtr b(a);
    cout << "a: " << *a << ", b: " << *b << endl;
    a->i = 2;
    cout << "a: " << *a << ", b: " << *b << endl;
    ValuePtr c = a;
    cout << "a: " << *a << ", b: " << *b << ", c: " << *c << endl;
    c = b;
    cout << "a: " << *a << ", b: " << *b << ", c: " << *c << endl;

    return 0;
}
