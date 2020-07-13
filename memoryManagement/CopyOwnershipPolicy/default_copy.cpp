#include <iostream>

/**
 * the Rule of Three states that if a class needs to have an overloaded 
 * copy constructor, copy assignment operator, ~or~ destructor, then 
 * it must also implement the other two as well to ensure that memory 
 * is managed consistently. 
 */

class MyClass
{
private:
    int *_myInt;

public:
    MyClass()
    {
        _myInt = (int *)malloc(sizeof(int));
    };
    ~MyClass()
    {
        free(_myInt);
    };
    void printOwnAddress() { std::cout << "Own address on the stack is " << this << std::endl; }
    void printMemberAddress() { std::cout << "Managing memory block on the heap at " << _myInt << std::endl; }
};

int main()
{
    // instantiate object 1
    MyClass myClass1;
    myClass1.printOwnAddress();
    myClass1.printMemberAddress();

    // copy object 1 into object 2
    MyClass myClass2(myClass1); // copy constructor
    myClass2.printOwnAddress();
    myClass2.printMemberAddress();

    // Both instanses has point to the same resource
    // but any of them can free it to make another crash

    return 0;
}