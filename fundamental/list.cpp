#include <iostream>
#include <list>

using namespace std;

void print(std::list<int> const &list)
{
    for (auto const &i : list)
    {
        std::cout << i << std::endl;
    }
}

// O(1) copy: tlist.splice(tlist_it, from_list, from_list_start, from_list_end)
int main()
{
    list<int> mylist1, mylist2;
    list<int>::iterator it;

    for (int i = 1; i < 4; i++)
        mylist1.push_back(i);

    for (int i = 0; i < 3; i++)
        mylist2.push_back(i * 10);

    it = mylist1.begin();
    ++it;

    // it 为指向mylist1的迭代器
    //   mylist1.splice(it, mylist2);
    //   print(mylist1);
    //                    it
    //                    |
    // mylist1: 1 0 10 20 2 3
    // mylist2: <empty>

    //  
    mylist2.splice(mylist2.begin(), mylist1, it);
    print(mylist2);
    // mylist2: 2 0 10 20
}