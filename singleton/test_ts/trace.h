#ifndef __trace_h
#define __trace_h

#include <thread>
#include <chrono>
#include <iostream>

class Trace {
public:
    Trace() {
        std::cerr << "Trace() begin\n"; 
        std::this_thread::sleep_for(std::chrono::seconds(3));
        std::cerr << "Trace() end\n"; 
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
