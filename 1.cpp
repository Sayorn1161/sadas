#ifndef UNIQUEPOINTER_H
#define UNIQUEPOINTER_H

template <typename T>
class UniquePointer {
public:
    UniquePointer(T* ptr = nullptr);
    ~UniquePointer();

    UniquePointer(const UniquePointer&) = delete;
    UniquePointer& operator=(const UniquePointer&) = delete;

    UniquePointer(UniquePointer&& other) noexcept;
    UniquePointer& operator=(UniquePointer&& other) noexcept;

    T& operator*() const;
    T* operator->() const;
    T* get() const;
    void reset(T* ptr = nullptr);
    T* release();

private:
    T* ptr;
};

#include "UniquePointer.cpp"

#endif // UNIQUEPOINTER_H
