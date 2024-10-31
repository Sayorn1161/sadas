#include "UniquePointer.h"

template <typename T>
UniquePointer<T>::UniquePointer(T* ptr) : ptr(ptr) {}

template <typename T>
UniquePointer<T>::~UniquePointer() {
    delete ptr;
}

template <typename T>
UniquePointer<T>::UniquePointer(UniquePointer&& other) noexcept : ptr(other.ptr) {
    other.ptr = nullptr;
}

template <typename T>
UniquePointer<T>& UniquePointer<T>::operator=(UniquePointer&& other) noexcept {
    if (this != &other) {
        delete ptr;
        ptr = other.ptr;
        other.ptr = nullptr;
    }
    return *this;
}

template <typename T>
T& UniquePointer<T>::operator*() const {
    return *ptr;
}

template <typename T>
T* UniquePointer<T>::operator->() const {
    return ptr;
}

template <typename T>
T* UniquePointer<T>::get() const {
    return ptr;
}

template <typename T>
void UniquePointer<T>::reset(T* ptr) {
    if (this->ptr != ptr) {
        delete this->ptr;
        this->ptr = ptr;
    }
}

template <typename T>
T* UniquePointer<T>::release() {
    T* temp = ptr;
    ptr = nullptr;
    return temp;
}
