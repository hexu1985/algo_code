#ifndef __rc_ptr_h
#define __rc_ptr_h

template <class T>
class RCPtr {
public:
    RCPtr(T* realPtr = 0);
    RCPtr(const RCPtr& rhs);
    RCPtr& operator=(const RCPtr& rhs);
    ~RCPtr();

    T *operator ->() const;
    T &operator *() const;

private:
    T *pointee; // dumb pointer this
    // object is emulating
    void init(); // common initialization
};

template <class T>
RCPtr<T>::RCPtr(T *realPtr): pointee(realPtr)
{
    init();
}

template <class T>
RCPtr<T>::RCPtr(const RCPtr &rhs): pointee(rhs.pointee)
{
    init();
}

template <class T>
void RCPtr<T>::init()
{
    if (pointee == 0) { // if the dumb pointer is
        return; // null, so is the smart one
    }

    if (pointee->isShareable() == false) { // if the value
        pointee = new T(*pointee); // isn't shareable,
    } // copy it

    pointee->addReference(); // note that there is now a
} // new reference to the value

template<class T>
RCPtr<T> &RCPtr<T>::operator =(const RCPtr &rhs)
{
    if (pointee != rhs.pointee) { // skip assignments
        // where the value
        // doesn't change
        if (pointee) {
            pointee->removeReference(); // remove reference to
        } // current value
        pointee = rhs.pointee; // point to new value
        init(); // if possible, share it
    } // else make own copy
    return *this;
}

template<class T>
RCPtr<T>::~RCPtr()
{
    if (pointee)pointee->removeReference();
}

template<class T>
T *RCPtr<T>::operator ->() const { return pointee; }

template<class T>
T &RCPtr<T>::operator *() const { return *pointee; }

#endif
