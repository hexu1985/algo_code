#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/chrono.hpp>
#include "thread.h"

void print_int(int i)
{
	std::cout << __func__ << "(" << i << ")" << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(50));
}

void print_string(std::string str)
{
	std::cout << __func__ << "(" << str << ")" << std::endl;
    boost::this_thread::sleep_for(boost::chrono::milliseconds(50));
}

class Foo {
	int n_;
public:
	Foo(int n): n_(n) {}

	void print()
	{
		std::cout << "Foo::" << __func__ << "(" << n_++ << ")" << std::endl;
        boost::this_thread::sleep_for(boost::chrono::milliseconds(50));
	}
};

class Base {
public:
    virtual void print() 
    {
        std::cout << "Base::print" << std::endl;
        boost::this_thread::sleep_for(boost::chrono::milliseconds(50));
    }
};

class Derived_A : public Base {
public:
    virtual void print() 
    {
        std::cout << "Derived_A::print" << std::endl;
        boost::this_thread::sleep_for(boost::chrono::milliseconds(50));
    }
};

class Derived_B : public Base {
public:
    virtual void print() 
    {
        std::cout << "Derived_B::print" << std::endl;
        boost::this_thread::sleep_for(boost::chrono::milliseconds(50));
    }
};

int main()
{
	Foo foo(1);
    Thread mythread("test");
    mythread.start();

	boost::shared_ptr<Task_queue> task_queue = mythread.get_task_queue();
	for (int i = 0; i < 10; i++) {
		task_queue->push_task(make_task(boost::bind(print_int, i)));
		task_queue->push_task(make_task(boost::bind(print_string, std::string("hello"))));
		task_queue->push_task(make_task(boost::bind(&Foo::print, &foo)));
	}
    Base base;
    Derived_A derived_a;
    Derived_B derived_b;

    Base *p1 = &base;
    Base *p2 = &derived_a;
    Base *p3 = &derived_b;

    task_queue->push_task(make_task(boost::bind(&Base::print, p1)));
    task_queue->push_task(make_task(boost::bind(&Base::print, p2)));
    task_queue->push_task(make_task(boost::bind(&Base::print, p3)));

    mythread.stop();
	return 0;
}

