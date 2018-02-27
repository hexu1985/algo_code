#ifndef __trace_h
#define __trace_h

#include <iostream>

class Trace {
public:
    Trace()
    {
        std::cout << "Trace::Trace()" << std::endl;
    }

    Trace(const Trace &)
    {
        std::cout << "Trace::Trace(const Trace &)" << std::endl;
    }

    Trace &operator =(const Trace &)
    {
        std::cout << "Trace &Trace::operator =(const Trace &)" << std::endl;
        return *this;
    }

#if __cplusplus >= 201103L
    Trace(Trace &&)
    {
        std::cout << "Trace::Trace(Trace &&)" << std::endl;
    }

    Trace &operator =(Trace &&)
    {
        std::cout << "Trace &Trace::operator =(Trace &&)" << std::endl;
        return *this;
    }
#endif

    virtual ~Trace()
    {
        std::cout << "Trace::~Trace()" << std::endl;
    }
};

#endif
