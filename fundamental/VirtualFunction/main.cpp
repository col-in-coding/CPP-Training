#include <iostream>

class Animal{
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