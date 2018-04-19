#ifndef __singleton_h
#define __singleton_h

template <typename T>
class Singleton {
private:
    static T *instance_;

public:
    static T &getInstance()
    {
        if (instance_ == nullptr) {
            instance_ = new T;
        }
        return *instance_;
    }
};

template <typename T>
T *Singleton<T>::instance_ = nullptr;

#endif
