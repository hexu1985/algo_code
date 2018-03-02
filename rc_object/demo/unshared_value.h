#ifndef __unshared_value_h
#define __unshared_value_h

#include "rc_object.h"
#include "value.h"

class UnsharedValue: public RCObject, public Value {
public:
    UnsharedValue(int i): Value(i)
    {
        RCObject::markUnshareable();
    }

    UnsharedValue(UnsharedValue &rhs): RCObject(rhs), Value(rhs)
    {
        RCObject::markUnshareable();
    }

    ~UnsharedValue() {}
};

#endif
