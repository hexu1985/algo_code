#ifndef __shared_value_h
#define __shared_value_h

#include "rc_object.h"
#include "value.h"

class SharedValue: public RCObject, public Value {
public:
    SharedValue(int i): Value(i) {}
    ~SharedValue() {}
};

#endif
