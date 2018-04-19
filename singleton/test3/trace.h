#ifndef __trace_h
#define __trace_h

#include "singleton.h"
#include <iostream>

class Trace {
private:
    Trace() {
        std::cerr << "Trace()\n"; 
    }

    friend class Singleton<Trace>;

public:
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
    
    static Trace &getInstance() {
        return Singleton<Trace>::getInstance();
    }
};

#endif
