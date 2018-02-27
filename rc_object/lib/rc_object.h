#ifndef __rc_object_h
#define __rc_object_h

class RCObject {
public:
    RCObject();
    RCObject(const RCObject& rhs);
    RCObject& operator=(const RCObject& rhs);
    virtual ~RCObject() = 0;

    void addReference();
    void removeReference();
    void markUnshareable();

    bool isShareable() const;
    bool isShared() const;

private:
    int refCount;
    bool shareable;
};

#endif
