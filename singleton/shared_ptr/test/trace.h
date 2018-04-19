#ifndef __trace_h
#define __trace_h

#include <iostream>

class Trace {
public:
    Trace() {
        std::cerr << "Trace()\n"; 
    }

    ~Trace() {
        std::cerr << "~Trace()\n"; 
    }

    void step_1() {
        std::cerr << "step_1\n";
    }

    void step_2() {
        std::cerr << "step_2\n";
    }

    void step_3() {
        std::cerr << "step_3\n";
    }
};

#endif
