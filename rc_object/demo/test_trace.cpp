#include "trace.h"
#include <utility>

int main()
{
    Trace a;
    Trace b(a);
    Trace c = a;
    c = b;

#if __cplusplus >= 201103L
    Trace d(std::move(a));
    Trace e = std::move(b);
    e = std::move(c);
#endif

    return 0;
}
