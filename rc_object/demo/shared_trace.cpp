#include "shared_trace.h"
#include <utility>
#include "rc_ptr.h"

typedef RCPtr<SharedTrace> TracePtr;

int main()
{
    TracePtr a(new SharedTrace);
    TracePtr b(a);
    TracePtr c = a;
    c = b;

#if __cplusplus >= 201103L
    TracePtr d(std::move(a));
    TracePtr e = std::move(b);
    e = std::move(c);
#endif

    return 0;
}
