#ifndef __singleton_h
#define __singleton_h

#include <mutex>

template <typename T>
class Singleton {
private:
    static T *instance_;
    static std::once_flag once_;

public:
    static T &getInstance()
    {
        std::call_once(once_, &newInstance);
        return *instance_;
    }

private:
    Singleton(const Singleton &) = delete;
    Singleton &operator =(const Singleton &) = delete;

    static void newInstance()
    {
        instance_ = new T;
    }
};

template <typename T>
T *Singleton<T>::instance_ = nullptr;

template <typename T>
std::once_flag Singleton<T>::once_;

#endif
