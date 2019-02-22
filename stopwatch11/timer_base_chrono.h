#ifndef TIMER_BASE_CHRONO_H
#define TIMER_BASE_CHRONO_H

#include <chrono>

class TimerBaseChrono {
public:
	//	clears the timer
	TimerBaseChrono() : m_start(std::chrono::system_clock::time_point::min()) { }

	//  clears the timer
	void Clear() { 
        using std::chrono::system_clock;
		m_start = system_clock::time_point::min(); 
	}

	//	returns true if the timer is running
	bool IsStarted() const {
        using std::chrono::system_clock;
		return (m_start != system_clock::time_point::min());
	}

	//	start the timer
	void Start()            { m_start = std::chrono::system_clock::now(); }

	//	get the number of milliseconds since the timer was started
	unsigned long GetMs() {
        using std::chrono::system_clock;
        using std::chrono::duration_cast;
        using std::chrono::milliseconds;
		if (IsStarted()) {
			system_clock::duration diff;
			diff = system_clock::now() - m_start;
			return (unsigned)(duration_cast<milliseconds>(diff).count());
		}
		return 0;
	}

private:
	std::chrono::system_clock::time_point m_start;
}; 

#endif
