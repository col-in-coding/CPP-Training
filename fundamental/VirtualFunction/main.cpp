#include <iostream>

class Animal{
    /**
     * A pure virtual function has the side effect of making its class abstract.
     * This means that the class cannot be instantiated. 
     * Instead, only classes that derive from the abstract class 
     * and override the pure virtual function can be instantiated.
     */
    virtual void Talk() const = 0;
};

class Human : public Animal{
public:
    void Talk() const {
        std::cout << "Hello\n";
    }
};

int main() {
    // Animal animal;
    Human human;
    human.Talk();
}