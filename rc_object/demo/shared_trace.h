#ifndef __shared_trace_h
#define __shared_trace_h

#include "rc_object.h"
#include "trace.h"

class SharedTrace: public RCObject, private Trace {
public:
    ~SharedTrace() {}
};

#endif
