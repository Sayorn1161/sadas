#include "SharedPointer.h"

template <typename T>
SharedPointer<T>::SharedPointer(T* ptr) : ptr(ptr), refCount(new int(1)) {}

template <typename T>
SharedPointer<T>::~SharedPointer() {
    releaseRef();
}

template <typename T>
SharedPointer<T>::SharedPointer(const SharedPointer& other) : ptr(other.ptr), refCount(other.refCount) {
    addRef();
}

template <typename T>
SharedPointer<T>& SharedPointer<T>::operator=(const SharedPointer& other) {
    if (this != &other) {
        releaseRef();
        ptr = other.ptr;
        refCount = other.refCount;
        addRef();
    }
    return *this;
}

template <typename T>
SharedPointer<T>::SharedPointer(SharedPointer&& other) noexcept : ptr(other.ptr), refCount(other.refCount) {
    other.ptr = nullptr;
    other.refCount = nullptr;
}

template <typename T>
SharedPointer<T>& SharedPointer<T>::operator=(SharedPointer&& other) noexcept {
    if (this != &other) {
        releaseRef();
        ptr = other.ptr;
        refCount = other.refCount;
        other.ptr = nullptr;
        other.refCount = nullptr;
    }
    return *this;
}

template <typename T>
T& SharedPointer<T>::operator*() const {
    return *ptr;
}

template <typename T>
T* SharedPointer<T>::operator->() const {
    return ptr;
}

template <typename T>
T* SharedPointer<T>::get() const {
    return ptr;
}

template <typename T>
void SharedPointer<T>::reset(T* ptr) {
    if (this->ptr != ptr) {
        releaseRef();
        this->ptr = ptr;
        refCount = new int(1);
    }
}

template <typename T>
void SharedPointer<T>::addRef() {
    if (refCount) {
        ++(*refCount);
    }
}

template <typename T>
void SharedPointer<T>::releaseRef() {
    if (refCount && --(*refCount) == 0) {
        delete ptr;
        delete refCount;
    }
}
