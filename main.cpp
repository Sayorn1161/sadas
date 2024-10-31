#include "UniquePointer.h"
#include "SharedPointer.h"
#include <iostream>

class Test {
public:
    Test(int value) : value(value) {
        std::cout << "Test created: " << value << std::endl;
    }
    ~Test() {
        std::cout << "Test destroyed: " << value << std::endl;
    }
    void show() const {
        std::cout << "Value: " << value << std::endl;
    }
private:
    int value;
};

void testUniquePointer() {
    UniquePointer<Test> ptr1(new Test(10));
    ptr1->show();
    UniquePointer<Test> ptr2 = std::move(ptr1);
    if (ptr1.get() == nullptr) {
        std::cout << "ptr1 is nullptr" << std::endl;
    }
    ptr2->show();
}

void testSharedPointer() {
    SharedPointer<Test> ptr1(new Test(20));
    {
        SharedPointer<Test> ptr2 = ptr1;
        ptr2->show();
    }
    ptr1->show();
}

int main() {
    std::cout << "Testing UniquePointer:" << std::endl;
    testUniquePointer();

    std::cout << "\nTesting SharedPointer:" << std::endl;
    testSharedPointer();

    return 0;
}
