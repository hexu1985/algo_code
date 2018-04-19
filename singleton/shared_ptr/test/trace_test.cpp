#include "singleton.h"
#include "trace.h"

int main(int argc, char *argv[]) {
    auto trace = Singleton<Trace>::getInstance();
    trace->step_1();
    trace->step_2();
    trace->step_3();

    // will return the existing instance
    auto trace2 = Singleton<Trace>::getInstance();
    trace2->step_1();
    trace2->step_2();
    trace2->step_3();

    return 0;
}

