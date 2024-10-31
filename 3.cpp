#ifndef SHAREDPOINTER_H
#define SHAREDPOINTER_H

template <typename T>
class SharedPointer {
public:
    SharedPointer(T* ptr = nullptr);
    ~SharedPointer();

    SharedPointer(const SharedPointer& other);
    SharedPointer& operator=(const SharedPointer& other);

    SharedPointer(SharedPointer&& other) noexcept;
    SharedPointer& operator=(SharedPointer&& other) noexcept;

    T& operator*() const;
    T* operator->() const;
    T* get() const;
    void reset(T* ptr = nullptr);

private:
    T* ptr;
    int* refCount;

    void addRef();
    void releaseRef();
};

#include "SharedPointer.cpp"

#endif // SHAREDPOINTER_H
