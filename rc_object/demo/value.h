#ifndef __Value_h
#define __Value_h

#include <iostream>
#include "trace.h"

class Value: private Trace {
public:
    int i;

    Value(int i): i(i) {}
};

std::ostream &operator <<(std::ostream &os, const Value &val)
{
    os << val.i;
    return os;
}

#endif
