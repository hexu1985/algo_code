#include "singleton.h"
#include "trace.h"

int main(int argc, char *argv[]) {
    Trace &trace = Singleton<Trace>::getInstance();
    trace.step_1();
    trace.step_2();
    trace.step_3();

    // will return the existing instance
    Trace &trace2 = Singleton<Trace>::getInstance();
    trace2.step_1();
    trace2.step_2();
    trace2.step_3();

    return 0;
}

