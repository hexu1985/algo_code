#include "unshared_trace.h"
#include <utility>
#include "rc_ptr.h"

typedef RCPtr<UnsharedTrace> TracePtr;

int main()
{
    UnsharedTrace *ptr = new UnsharedTrace;
    TracePtr a(ptr);
    TracePtr b(a);
    TracePtr c = a;
    c = b;

#if __cplusplus >= 201103L
    TracePtr d(std::move(a));
    TracePtr e = std::move(b);
    e = std::move(c);
#endif

    delete ptr;
    return 0;
}
