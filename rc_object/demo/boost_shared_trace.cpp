#include "trace.h"
#include <utility>
#include <boost/shared_ptr.hpp>

typedef boost::shared_ptr<Trace> TracePtr;

int main()
{
    TracePtr a(new Trace);
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
