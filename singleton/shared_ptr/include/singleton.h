#ifndef __singleton_h
#define __singleton_h

#include <memory>

template <typename T>
class Singleton {
private:
    static std::shared_ptr<T> instance_;

public:
    static std::shared_ptr<T> &getInstance()
    {
        if (instance_ == nullptr) {
            instance_ = std::make_shared<T>();
        }
        return instance_;
    }
};

template <typename T>
std::shared_ptr<T> Singleton<T>::instance_;

#endif
