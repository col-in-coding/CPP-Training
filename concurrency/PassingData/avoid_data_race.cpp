#include <iostream>
#include <thread>
#include <future>

class Vehicle
{
public:
    //default constructor
    Vehicle() : _id(0), _name(new std::string("Default Name"))
    {
        std::cout << "Vehicle #" << _id << " Default constructor called" << std::endl;
    }

    //initializing constructor
    Vehicle(int id, std::string name) : _id(id), _name(new std::string(name))
    {
        std::cout << "Vehicle #" << _id << " Initializing constructor called" << std::endl;
    }

    // Overwrite the constructor for deep copy
    // to avoid data race
    Vehicle(Vehicle const &src)
    {
        _id = src._id;
        if (src._name != nullptr)
        {
            _name = new std::string;
            *_name = *src._name;
        }
        std::cout << "Vehicle #" << _id << " copy constructor called" << std::endl;
    };

    // setter and getter
    void setID(int id) { _id = id; }
    int getID() { return _id; }
    void setName(std::string name) {
        // hidden data buffer, this may cause shallow copy
        *_name = name;
    }
    std::string getName() {return *_name; }

private:
    int _id;
    std::string *_name;
};

int main()
{
    // create instances of class Vehicle
    Vehicle v0;    // default constructor
    Vehicle v1(1, "Vehicle 1"); // initializing constructor

    // launch a thread that modifies the Vehicle name
    std::future<void> ftr = std::async([](Vehicle v) {
        std::this_thread::sleep_for(std::chrono::milliseconds(500)); // simulate work
        v.setID(2);
        v.setName("Vehicle 2");
    },v0);

    // no data race
    v0.setID(3);
    // has data race
    v0.setName("Vehicle 3");

    ftr.wait();
    std::cout << "Vehicle #" << v0.getID() << std::endl;
    std::cout << v0.getName() << std::endl;

    return 0;
}