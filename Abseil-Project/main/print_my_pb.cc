#include <iostream>
#include "proto/addressbook.pb.h"

int main(int argc, char const *argv[])
{
    demo::AddressBook address_book;
    demo::Person p1;
    p1.set_name("Colin");
    p1.set_id(1000);
    
    auto* my_email = p1.mutable_email();
    *my_email = "hxl.colin@gmail.com";

    auto phone1 = p1.add_phone();
    phone1->set_number("312-307-2050");
    phone1->set_type(demo::Person::MOBILE);

    demo::Person* next_person = address_book.add_people();
    // auto next_person = address_book.add_people();
    next_person->CopyFrom(p1);
    
    std::cout << address_book.DebugString() << std::endl;
    return 0;
}
