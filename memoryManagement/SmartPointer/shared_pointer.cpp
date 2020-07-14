#include <iostream>
#include <memory>


class MyClass
{
public:
    std::shared_ptr<MyClass> _member;
    ~MyClass() { std::cout << "Destructor of MyClass called" << std::endl; }
};


int main()
{
    std::shared_ptr<int> shared1(new int);
    std::cout << "shared pointer count = " << shared1.use_count() << std::endl; // 1

    {
        std::shared_ptr<int> shared2 = shared1;
        std::cout << "shared pointer count = " << shared1.use_count() << std::endl; // 2
    }
    
    std::cout << "shared pointer count = " << shared1.use_count() << std::endl; // 1


    // usint reset() to redirect the memory
    std::shared_ptr<MyClass> shared(new MyClass);
    std::cout << "shared pointer count = " << shared.use_count() << std::endl; // 1

    shared.reset(new MyClass);
    std::cout << "shared pointer count = " << shared.use_count() << std::endl; // 1


    std::shared_ptr<MyClass> myClass1(new MyClass);
    std::shared_ptr<MyClass> myClass2(new MyClass);
    // Shared pointer can cause deadlock and memory leak at end of the scope
    // myClass1->_member = myClass2;
    // myClass2->_member = myClass1;

    // No way to convert from shared pointer

    return 0;
}