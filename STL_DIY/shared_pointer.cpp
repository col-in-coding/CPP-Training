/*
实现一个shared_pointer
考察知识点：1.资源管理 2.模板类 3.构造函数 4.重写运算符
*/
#include <string>
#include <iostream>
#include <memory>

namespace my{
    template <typename T>
    class shared_pointer
    {
    private:
        T *_vptr = nullptr;
        static int _cnt;
    public:
        // 默认构造函数
        shared_pointer(){};
        shared_pointer(T* value){
            // std::cout << "using default constructor" << std::endl;
            _vptr = value;
            _cnt++;
        };

        // 拷贝构造函数
        shared_pointer(const shared_pointer<T>& shared_ptr)
        {
            // std::cout << "using copy constructor" << std::endl;
            // The access modifiers work on class level, and not on object level.
            _vptr = shared_ptr._vptr;
            _cnt++;
        };

        // 重置指针运算
        T* operator->(){
            return _vptr;
        }

        // 获取计数
        int use_count(){
            return _cnt;
        }

        ~shared_pointer()
        {
            // 资源释放
            --_cnt;
            if (_cnt == 0)
            {
                delete _vptr;
            }
        };
    };
    template <typename T>
    int shared_pointer<T>::_cnt = 0;
}

class Student
{
public:
    Student(std::string name): _name(name){};
    std::string get_name(){return _name;}
private:
    std::string _name;
};

int main(){
    // Normal Pointer
    // Student *stu_ptr = new Student("Colin");
    // std::cout << stu_ptr->get_name() << std::endl;
    // delete stu_ptr;
    
/*
    // STL Smart Pointer
    // 1. initialization
    std::shared_ptr<Student> stu_ptr(new Student("Colin"));
    // 2. use resource
    std::cout << stu_ptr->get_name() << std::endl;
    // 3. assign to another pointer
    std::shared_ptr<Student> stu_ptr2 = stu_ptr;
    // 4. get use count
    std::cout << stu_ptr2.use_count() << std::endl;
*/

    // My Smart Pointer
    // 1. initialization
    my::shared_pointer<Student> stu_ptr = new Student("Colin");
    // 2. use resource
    std::cout << stu_ptr->get_name() << std::endl;
    // 3. assign to another pointer
    my::shared_pointer<Student> stu_ptr2 = stu_ptr;
    // 4. get use count
    std::cout << stu_ptr2.use_count() << std::endl;
    return 0;
}