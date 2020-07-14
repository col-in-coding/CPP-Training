#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> mySharedPtr(new int);
    std::cout << "shared pointer count = " << mySharedPtr.use_count() << std::endl; // 1

    std::weak_ptr<int> myWeakPtr1(mySharedPtr);
    std::weak_ptr<int> myWeakPtr2(myWeakPtr1);
    std::cout << "shared pointer count = " << mySharedPtr.use_count() << std::endl; // 1

    // std::weak_ptr<int> myWeakPtr3(new int); // COMPILE ERROR

    // converting to shared pointer
    std::shared_ptr<int> sharedPtr = myWeakPtr1.lock();

    return 0;
}