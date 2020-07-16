#include <iostream>
#include <thread>

class Vehicle
{
public:
    Vehicle() : _id(0) {}
    void addID(int id) { _id = id; }
    void printID()
    {
        std::cout << "Vehicle ID=" << _id << std::endl;
    }

private:
    int _id;
};

int main()
{
    // Add additional argument for the object on which to invoke the member function
    Vehicle v1, v2;
    // v1 object is passed by value, so won't affect the original one in main scope
    std::thread t1 = std::thread(&Vehicle::addID, v1, 1);
    // v2 object is passed by reference, changes also in main scope
    std::thread t2 = std::thread(&Vehicle::addID, &v2, 2);
    // wait for thread to finish
    t1.join();
    t2.join();
    // print Vehicle id
    v1.printID(); // 0
    v2.printID(); // 2


    // using heap-allocated object to ensure the object lives long till the thread ends
    std::shared_ptr<Vehicle> v(new Vehicle);
    std::thread t = std::thread(&Vehicle::addID, v, 1); // call member function on object v
    // wait for thread to finish
    t.join();
    // print Vehicle id
    v->printID();

    return 0;
}