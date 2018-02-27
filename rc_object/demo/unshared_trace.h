#ifndef __unshared_trace_h
#define __unshared_trace_h

#include "rc_object.h"
#include "trace.h"

class UnsharedTrace: public RCObject, private Trace {
public:
    UnsharedTrace()
    {
        RCObject::markUnshareable();
    }

    UnsharedTrace(UnsharedTrace &rhs): RCObject(rhs), Trace(rhs)
    {
        RCObject::markUnshareable();
    }

    ~UnsharedTrace() {}
};

#endif
