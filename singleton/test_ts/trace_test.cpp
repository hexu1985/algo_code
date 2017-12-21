#include <thread>
#include "singleton.h"
#include "trace.h"

void func()
{
    Trace &trace = Singleton<Trace>::getInstance();
    trace.step_1();
    trace.step_2();
    trace.step_3();
}

int main(int argc, char *argv[]) {
    std::thread th(func);

    // will return the existing instance
    std::thread th2(func);

    th.join();
    th2.join();

    return 0;
}

