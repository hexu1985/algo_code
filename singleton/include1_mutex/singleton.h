#ifndef __singleton_h
#define __singleton_h

#include <mutex>

template <typename T>
class Singleton {
private:
    static T *instance_;
    static std::mutex mtx_;

public:
    static T &getInstance()
    {
        if (instance_ == nullptr) {
            std::lock_guard<std::mutex> lck(mtx_);
            if (instance_ == nullptr)
                instance_ = new T;
        }
        return *instance_;
    }
};

template <typename T>
T *Singleton<T>::instance_ = nullptr;

template <typename T>
std::mutex Singleton<T>::mtx_;

#endif
