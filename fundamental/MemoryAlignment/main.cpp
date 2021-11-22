#include <iostream>

struct
{
    int i;    
    char c1;  
    char c2;  
}x1;

struct{
    char c1;  
    int i;    
    char c2;  
}x2;

struct{
    char c1;
    int i;
    char c2;
    double d1;
}x3;

int main()
{
    std::cout << sizeof(x1) << std::endl;  // 输出8
    std::cout << sizeof(x2) << std::endl;  // 输出12
    std::cout << sizeof(x3) << std::endl;  // 输出24
    return 0;
}