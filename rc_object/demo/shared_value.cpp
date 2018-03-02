#include "shared_value.h"
#include <utility>
#include <iostream>
#include "rc_ptr.h"

typedef RCPtr<SharedValue> ValuePtr;

using namespace std;

int main()
{
    ValuePtr a(new SharedValue(1));
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
