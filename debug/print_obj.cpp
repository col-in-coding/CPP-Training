/*
 Basic Command Line Instructions
 g++ -g print_obj.cpp -o print_obj
 gdb print_obj
 
 gdb commands:
 b print_obj.cpp:60 // create a break point
 r
 set print object on // print the drived type if using inheritance
 set print pretty on // print in a more readable format
 p s1
*/

#include <iostream>
#include <memory>
#include <string>

class People
{
public:
    People(std::string name, int age):name(name), age(age){};
    std::string getName();
    int getAge();

private:
    std::string name;
    int age;
};

class Student : public People
{
public:
    Student(std::string name, int age, std::string address): People(name, age), address(address){};
    std::string getAddress()
    {
        return address;
    }

    void setContactPerson(People *person)
    {
        contact_person = std::make_unique<People>(*person);
    }

private:
    std::string address;
    std::unique_ptr<People> contact_person;
};

std::string People::getName()
{
    return name;
}

int main()
{
    Student s1 = Student("Colin", 18, "HiTech 12B 20F");
    People *contact_p = new People("Li", 50);
    s1.setContactPerson(contact_p);

    std::cout << "Name: " << s1.getName() << std::endl;
    std::cout << "Address: " << s1.getAddress() << std::endl;

    return 0;
}