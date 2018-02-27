#include "value.h"
#include <utility>
#include <iostream>
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<Value> ValuePtr;

using namespace std;

int main()
{
    ValuePtr a(new Value(1));
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
