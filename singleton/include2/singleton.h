#ifndef __singleton_h
#define __singleton_h

template <typename T>
class Singleton {
private:
    static T instance_;

public:
    static T &getInstance()
    {
        return instance_;
    }
};

template <typename T>
T Singleton<T>::instance_;

#endif
